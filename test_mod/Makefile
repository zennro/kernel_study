obj-m += test.o
PWD=$(shell pwd)
build:
	make -C /usr/src/linux-headers-3.13.0-35-generic SUBDIRS=$(PWD) modules
clean:
	rm -f modules.*  Module.*  *.o *.mod.* *.ko
	rm -fr .tmp_versions
	rmmod test
install: build
	insmod ./test.ko

