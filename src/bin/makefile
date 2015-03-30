include ../../makevariables 

%.bin:
	cd ../obj && $(cc) $(std) $(obj) -o ../bin/$@
	./$@

clean:
	rm -f *.bin
