#include "ImageWrite.hpp"
#include <iostream>

static std::vector<uint8_t> bgr24(const Screen& screen);

void
writeBMP24bit(const std::string& path,
			  const Screen&      screen,
			  const uint32_t&    dpi) {
	
	std::ofstream file;
	file.open(path,
			  std::ofstream::out |
			  std::ofstream::binary |
			  std::ofstream::trunc);
	if (!file) {
		file.close();
		throw std::exception();
	}
	
	// i think that 4 should be 3 as there are 3 bytes per rgb triple
	uint32_t fileheadersize  = 14;
	uint32_t imageheadersize = 40;
	uint32_t headersize = fileheadersize + imageheadersize;
	uint32_t imagesize = screen.width * screen.height * 3;
	uint32_t filesize  = fileheadersize  +
		imageheadersize +
		imagesize;
	uint16_t colorsize = 24; // number of bits in color
	
	file.put('B');
	file.put('M');

	file.write((const char*) &filesize, sizeof(uint32_t));

	{
		char unused[4] = {};
		file.write(unused, sizeof(unused));
	}

	file.write((const char*) &headersize, sizeof(uint32_t));

	file.write((const char*) &imageheadersize, sizeof(uint32_t));

	file.write((const char*) &screen.width,  sizeof(uint32_t));
	file.write((const char*) &screen.height, sizeof(uint32_t));

	{
		uint16_t unknown_field = 1;
		file.write((const char*) &unknown_field, sizeof(uint16_t));
	}
	
	file.write((const char*) &colorsize, sizeof(uint16_t));

	{
		char unused[4] = {};
		file.write(unused, sizeof(unused));
	}

	file.write((const char*) &imagesize, sizeof(uint32_t));

	file.write((const char*) &dpi, sizeof(uint32_t));
	file.write((const char*) &dpi, sizeof(uint32_t));

	{
		char unused[8] = {};
		file.write(unused, sizeof(unused));
	}

	uint count = 0;
	uint padding = (4 - (screen.width * 3)%4)%4;
	for (auto &byte : bgr24(screen)){
		file.put(byte);
		count++;
		if (count == screen.width*3) {
			for (uint i = 0; i < padding; i++) {
				file.put(0);
			}
			count = 0;
		}
	}
	file.close();
}


// outputs the data needed in bmp format
static std::vector<uint8_t>
bgr24(const Screen& screen){
	auto raw = std::vector<uint8_t>();
	raw.reserve(screen.width * screen.height * 3);

	// rows in a bmp are backwards
	// because why not lets just make them as hard to understand as possible
	for (uint y = 1; y <= screen.height; y++){
		for(uint x = 0; x < screen.width; x++) {
			auto px = Pixel(screen.pixels[(screen.height - y)*screen.width + x]);
			raw.push_back(px.b);
			raw.push_back(px.g);
			raw.push_back(px.r);	
		}
	}
	return raw;
}
