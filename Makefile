# Makefile for crc32.c
# see https://github.com/tmalbonph/crc32/blob/master/LICENSE

all: crc32


crc32: crc32.c
		mkdir -p build && cd ./build && cmake ../ && cp -f Makefile Makefile.crc32 && make -f Makefile.crc32 1> /dev/null

install: crc32
		cd ./build && sudo make -f Makefile.crc32 install

test: crc32
		@echo "Testing crc32.c w/o -id"
		@build/crc32 crc32.c
		@echo "Testing crc32.c with -id"
		@build/crc32 crc32.c -id

clean: force
		if [ -d build/ ]; then rm -rf ./build ; fi

force:


# eof: Makefile