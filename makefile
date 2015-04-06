include vars.make

all:
	$(MAKE) -C src/obj $(obj)
	$(MAKE) -C src/bin $(bin)

bin:
	$(MAKE) -C src/obj $(obj)
	$(MAKE) -C src/bin $(bin)

run: bin
	src/bin/$(bin)

run-save: bin
	src/bin/$(bin) -p out/$(shell date +%s).bmp

clean:
	$(MAKE) -C src/bin $@
	$(MAKE) -C src/obj $@

	$(MAKE) -C test/bin $@
	$(MAKE) -C test/obj $@
