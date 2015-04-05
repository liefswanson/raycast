#include "Screen.hpp"
#include <fstream>
#include <string>
#include <array>


void writeBMP24bit(const std::string& path,
				   const Screen&      screen,
				   const uint32_t&    dpi);
