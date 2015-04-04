include ../../vars.make 

$(bin): $(addprefix ../obj/, $(obj))
	cd ../obj && $(cc) $(std) $(lflags) $(obj) -o ../bin/$@

../obj/%.o:
	$(MAKE) -C ../obj $*.o

clean:
	rm -f *.bin
