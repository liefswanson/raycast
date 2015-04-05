include ../../vars.make

%.o: ../%.cpp ../%.hpp
	$(cc) $(std) $(flags) -c ../$*.cpp -o $@ 

clean:
	rm -f *.o
