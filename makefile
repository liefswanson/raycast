include makevariables

all: $(bin) $(test_bin)
	date

bin: $(bin)
	date

test: $(test_bin)
	date

run: all
	src/bin/$(bin)

$(bin): $(obj)
	$(MAKE) -C src/bin $@

$(obj): $(src)
	$(MAKE) -C src/obj $@

$(src):
	$(MAKE) -C src $@

$(test_bin): $(test_obj)
	$(MAKE) -C test/bin $@

$(test_obj): $(test_src)
	$(MAKE) -C test/obj $@

$(test_src):
	$(MAKE) -C test $@

clean:
	$(MAKE) -C src/bin $@
	$(MAKE) -C src/obj $@

	$(MAKE) -C test/bin $@
	$(MAKE) -C test/obj $@
