#include "ImageWrite.hpp"
#include <iostream>


void writeBMP(const std::string& path,
			  const uint32_t& width, const uint32_t& height, const uint32_t& dpi,
			  const std::vector<uint8_t>& imagedata, const uint16_t& colorsize) {

		std::ofstream file;
		file.open(path,
				  std::ofstream::out |
				  std::ofstream::binary |
				  std::ofstream::trunc);
		if (!file) {
			throw std::exception();
		}
	
		// i think that 4 should be 3 as there are 3 bytes per rgb triple
		uint32_t fileheadersize  = 14;
		uint32_t imageheadersize = 40;
		uint32_t headersize = fileheadersize + imageheadersize;
		uint32_t imagesize = width * height * 3;
		uint32_t filesize  = fileheadersize  +
			imageheadersize +
			imagesize;

		file.put('B');
		file.put('M');

		file.write((const char*) &filesize, sizeof(uint32_t));

		{
			char unused[4] = {};
			file.write(unused, sizeof(unused));
		}

		file.write((const char*) &headersize, sizeof(uint32_t));

		file.write((const char*) &imageheadersize, sizeof(uint32_t));

		file.write((const char*) &width,  sizeof(uint32_t));
		file.write((const char*) &height, sizeof(uint32_t));

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

		for (auto &byte : imagedata){
			file.put(byte);
		}

		file.close();
}
