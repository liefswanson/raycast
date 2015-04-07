include vars.make

all:
	$(MAKE) -C src/obj $(obj)
	$(MAKE) -C src/bin $(bin)

bin:
	$(MAKE) -C src/obj $(obj)
	$(MAKE) -C src/bin $(bin)

run: bin
	src/bin/$(bin) $(bin_args)
	convert out/output.bmp out/output.png
	rm out/output.bmp

run-save: bin
	src/bin/$(bin) $(bin_args) -p out/$(shell date +%s).bmp

clean:
	$(MAKE) -C src/bin $@
	$(MAKE) -C src/obj $@

	$(MAKE) -C test/bin $@
	$(MAKE) -C test/obj $@
