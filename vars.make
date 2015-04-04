cc       = clang++
std      = --std=c++14
flags    = -g -Wall
lflags   = -g -Wall

src      = Main.cpp Constants.cpp Settings.cpp ImageWrite.cpp ArgParse.cpp TermColor.cpp Scene.cpp Screen.cpp Pixel.cpp Cam.cpp Vec.cpp Light.cpp Color.cpp Sphere.cpp Object.cpp Plane.cpp Ray.cpp
obj      = $(src:.cpp=.o)
bin      = raycast.bin

test_src = 
test_obj = $(test_src:.cpp=.o)
test_bin = 
