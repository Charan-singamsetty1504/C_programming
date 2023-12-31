obj-m += param1.o

ifdef ARCH
	KDIR = /lib/modules/6.2.0-39-generic/build
else
	KDIR = /lib/modules/$(shell uname -r)/build
endif

all:
	make -C $(KDIR) M=$(shell pwd) modules
clean:
	make -C $(KDIR) M=$(shell pwd) clean

