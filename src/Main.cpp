#include "Main.hpp"
#include <fstream>


int main(int argc, char *argv[]) {
    std::cout << "rendering." << std::endl;

	std::ofstream file;
	file.open("derp.txt",
			  std::ofstream::out |
			  std::ofstream::binary |
			  std::ofstream::trunc);

	file.close();
	
    return 0;
}
