CC = clang
override CFLAGS += -g -w -O3 -fsanitize=fuzzer,address

all: libpngparser fuzzer_load_png fuzzer_load_png_name fuzzer_store_png_rgba

clean:
	rm -f libpngparser.a fuzzer_load_png fuzzer_load_png_name fuzzer_store_png_rgba *.o

.PHONY: all clean

libpngparser: pngparser.h pngparser.c crc.c crc.h
	$(CC) $(CFLAGS) -c pngparser.c crc.c
	ar rcs libpngparser.a pngparser.o crc.o

fuzzer_load_png:
	$(CC) $(CFLAGS) -o fuzzer_load_png fuzzer_load_png.c libpngparser.a -lz

fuzzer_load_png_name:
	$(CC) $(CFLAGS) -o fuzzer_load_png_name fuzzer_load_png_name.c libpngparser.a -lz

# fuzzer_store_png_palette:
# Fuzzes store_png RGBA file interface (no palette).

fuzzer_store_png_rgba:
	$(CC) $(CFLAGS) -o fuzzer_store_png_rgba fuzzer_store_png_rgba.c libpngparser.a -lz

fuzzer_store_png_name:
	$(CC) $(CFLAGS) -o fuzzer_store_png_name fuzzer_store_png_name.c libpngparser.a -lz
