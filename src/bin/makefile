include ../../vars.make 

$(bin): $(addprefix ../obj/, $(obj))
	cd ../obj && $(cc) -o ../bin/$@ $(std) $(obj) $(lflags)  

../obj/%.o:
	$(MAKE) -C ../obj $*.o

clean:
	rm -f *.bin
