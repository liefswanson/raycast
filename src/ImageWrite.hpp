#include "Screen.hpp"
#include <fstream>
#include <string>
#include <array>


void writeBMP(const std::string& path,
			  const uint32_t& width, const uint32_t& height, const uint32_t& dpi,
			  const std::vector<uint8_t>& imagedata,
			  const uint16_t& colorsize);
