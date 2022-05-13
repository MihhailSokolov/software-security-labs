#include "pngparser.h"

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  struct image *test_img;

  char *filename = NULL;
  if (Size > 0) {
      filename = (char *) Data;
  }
  
  // What would happen if we run multiple fuzzing processes at the same time?
  // Take a look at the name of the file.
  if (load_png(filename, &test_img) == 0)
  	free(test_img);

  // Always return 0
  return 0;
}
