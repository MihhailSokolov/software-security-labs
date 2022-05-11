# Answers

## Why did you need to change `is_png_chunk_valid`?
The change to `is_png_chunk_valid` was required to improve the effectiveness of fuzzing. Our change disabled the CRC check which would otherwise interfere with testing. Since the input data is (almost) randomly generated from the seeds, the CRC check would not pass for most of the variants of the data and we would not be able to test the program further.

## Why did you have to use `afl-clang` to compile the source (and not e.g. ordinary gcc)?
We use `afl-clang` instead of th usual compiler because during compilation it also adds the instrumentation which allows us to see which edges were reached and estimate the coverage and hence the effictiveness of fuzzing.

## How many crashes in total did AFL produce? How many unique crashes?
After running for 6 minutes and 12 seconds, the AFL produced 59.5k crashes out of which 15 were unique and saved.

## Why are hangs counted as bugs in AFL? Which type of attack can they be used for?
Hangs are counted as bugs because they essentially cause the same result as crashes - the problem is unusable. In a way, the hangs are even worse than crashes because they are harder to identify. Hangs are used for denial-of-service attacks.

Which interface of `libpngparser` remains untested by AFL (take a look at `pngparser.h`)?
The interface that remains untested is `int store_png(const char *filename, struct image *img, struct pixel *palette, uint8_t palette_length);`.