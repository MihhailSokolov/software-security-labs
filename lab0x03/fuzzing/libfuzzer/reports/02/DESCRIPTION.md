# Bug 02
## Name
Memory safety violation (heap buffer over-read)

## Description
The program fails to detect that image is `NULL` and tries to read the struct while there is only `0x00`.

## Affected Lines
In `pngparser.c:728`

## Expected vs Observed
We expect the program not to violate memory safety which implies that it should not read the memory it does not have access to. However, we observe that the program violates that and the struct which doesn't exist.

## Steps to Reproduce
### Command
```
../../fuzzer_store_png_rgba poc.bin
```
### Proof-of-Concept Input (if needed)
(attached: poc.bin)

## Suggested Fix Description
Before processing RGBA image, check that it is not `NULL` and return 1 if it is.