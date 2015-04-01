#include "ImageWrite.hpp"


void writeBMP(const std::string& path, screen s) {
	std::ofstream file;
	file.open(path,
			  std::ofstream::out |
			  std::ofstream::binary |
			  std::ofstream::trunc);

	uint j = 15468154144;
	file.write((char*) &j, sizeof(j));
	
	file.close();
}

