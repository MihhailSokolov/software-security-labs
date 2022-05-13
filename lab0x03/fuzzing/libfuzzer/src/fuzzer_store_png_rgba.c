#include "pngparser.h"

// LibFuzzer stub
//
int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size) {
  struct image *test_img = NULL;
  if (Size > 0) {
    test_img = Data;
  }

  store_png("image.png", test_img, NULL, 0);

  return 0;
}
