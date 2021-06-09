#include "pngparser.h"
#include <stdio.h>

// LibFuzzer stub
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  struct image *test_img;

  FILE *output = fopen("testfile.png", "wb");
  store_filesig(output);
  fclose(output);
  // What would happen if we run multiple fuzzing processes at the same time?
  // Take a look at the name of the file.
  if (store_png("testfile.png", &test_img, NULL, NULL) == 0)
  	free(test_img);

  // Always return 0
  return 0;
}
