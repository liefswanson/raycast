#include "Main.hpp"
#include "ImageWrite.hpp"
#include "Screen.hpp"
#include "Pixel.hpp"

screen s(640, 480, 72);

int main(int argc, char *argv[]) {
    std::cout << "rendering." << std::endl;

	for(uint32_t x = 0; x < s.width; x++) {
		for(uint32_t y = 0; y < s.height; y++) {
			
		}
	}

	
	writeBMP("out/derp.bmp",
			 s.width, s.height, s.dpi,
			 s.bgr24(), 24);
	
    return 0;
}
