#include "Main.hpp"
#include "ImageWrite.hpp"
#include "Screen.hpp"
#include "Pixel.hpp"

screen s(640, 480, 72);

int main(int argc, char *argv[]) {
    std::cout << "rendering." << std::endl;

	for (auto &px : s.pixels) {
		px.g = 1.0f;
	}
	
	writeBMP("derp.bmp", s);
	
    return 0;
}
