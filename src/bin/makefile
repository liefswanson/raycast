include ../../makevariables 

$(bin): $(addprefix ../obj/, $(obj))
	cd ../obj && $(cc) $(std) $(obj) -o ../bin/$@

../obj/%.o:
	$(MAKE) -C ../obj $*.o

clean:
	rm -f *.bin
