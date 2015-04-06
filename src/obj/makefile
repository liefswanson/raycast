include ../../vars.make

%.o: ../%.cpp ../%.hpp
	$(cc) -o $@ -c ../$*.cpp $(std) $(flags) 

clean:
	rm -f *.o
