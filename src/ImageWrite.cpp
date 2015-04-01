#include "ImageWrite.hpp"
#include <iostream>


void writeBMP(const std::string& path, const screen& s) {
	std::ofstream file;
	file.open(path,
			  std::ofstream::out |
			  std::ofstream::binary |
			  std::ofstream::trunc);

	
	std::vector<uint8_t> imagedata = s.bgr24();

	// i think that 4 should be 3 as there are 3 bytes per rgb triple
	uint8_t fileheadersize  = 14;
	uint8_t imageheadersize = 40;
	uint32_t imagesize = s.width * s.height * 3;
	uint32_t filesize  = fileheadersize +
		                 imageheadersize +
		                 imagesize;

	file.put('B');
	file.put('M');

	file.write((const char*) &filesize, 4);

	{
		char unused[4] = {};
		file.write((const char*) unused, sizeof(unused));
	}

	file.put(fileheadersize + imageheadersize);

	{
		char unused[3] = {};
		file.write((const char*) unused, sizeof(unused));
	}

	file.put(imageheadersize);

	{
		char unused[3] = {};
		file.write((const char*) unused, sizeof(unused));
	}

	file.write((const char*) &s.width,  4);
	file.write((const char*) &s.height, 4);

	file.put(1);
	file.put(0); // unused
	file.put(24); // size of 24bit rgb 
	file.put(0); // unused

	{
		char unused[4] = {};
		file.write((const char*) unused, sizeof(unused));
	}

	file.write((const char*) &imagesize, sizeof(imagesize));

	file.write((const char*) &s.dpi, sizeof(s.dpi));
	file.write((const char*) &s.dpi, sizeof(s.dpi));

	{
		char unused[8] = {};
		file.write((const char*) unused, sizeof(unused));
	}

	for (auto &byte : imagedata){
		file.put(byte);
	}
	
	std::cout << imagesize << std::endl;
	file.close();
}
