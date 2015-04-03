cc       = clang++
std      = --std=c++14

src      = Main.cpp ImageWrite.cpp Screen.cpp Pixel.cpp ArgParse.cpp TermColor.cpp Cam.cpp Vec.cpp 
obj      = $(src:.cpp=.o)
bin      = raycast.bin

test_src = 
test_obj = $(test_src:.cpp=.o)
test_bin = 
