CC = clang
override CFLAGS += -g -w -O3 -fsanitize=fuzzer,address

all: libpngparser fuzzer_load_png

clean:
	rm -f libpngparser.a fuzzer_load_png *.o

.PHONY: all clean

libpngparser: pngparser.h pngparser.c crc.c crc.h
	$(CC) $(CFLAGS) -c pngparser.c crc.c
	ar rcs libpngparser.a pngparser.o crc.o

fuzzer_load_png:
	$(CC) $(CFLAGS) -o fuzzer_load_png fuzzer_load_png.c libpngparser.a -lz

# TO DO: fuzzer_load_png_name:
# Fuzzes the filename argument of load_png.

# TO DO: fuzzer_store_png_rgba:
# Fuzzes store_png RGBA file interface (no palette).

# TO DO: fuzzer_store_png_palette:
# Fuzzes store_png palette file interface (fixed palette).

# TO DO: fuzzer_store_png_name:
# Fuzzes the filename argument of store_png.
