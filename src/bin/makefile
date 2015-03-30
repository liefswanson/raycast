include ../../makevariables 

%.bin:
	cd ../obj && $(cc) $(obj) -o ../bin/$@
	./$@

clean:
	rm -f *.bin
