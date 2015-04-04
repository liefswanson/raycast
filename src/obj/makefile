include ../../vars.make

%.o: ../%.cpp ../%.hpp
	cd ../ && $(cc) $(std) $(flags) -c $*.cpp -o obj/$@ 

clean:
	rm -f *.o
