include ../../makevariables

%.o: ../%.cpp ../%.hpp
	cd ../ && $(cc) $(std) -c $*.cpp -o obj/$@ 

clean:
	rm -f *.o
