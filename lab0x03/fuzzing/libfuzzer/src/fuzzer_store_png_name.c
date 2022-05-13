#include "pngparser.h"

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  struct image *test_img = NULL;

  char *filename = NULL;
  if (Size > 0) {
      filename = (char *) Data;
  }
  store_png(filename, test_img, NULL, 0);
  
  return 0;
}
