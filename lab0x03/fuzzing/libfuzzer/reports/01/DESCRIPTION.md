# Bug 01
## Name
Memory safety violation (accessing inaccessible memory)

## Description
The program fails to open the file with `FILE *input = fopen(filename, "rb");` on line 545 when filename is `NULL`. It tries to read memory with address `0x00`.

## Affected Lines
In `pngparser.c:545`

## Expected vs Observed
We expect the program not to violate memory safety which implies that it should not read the memory it does not have access to. However, we observe that the program violates that and tries to read memory with address `0x00`.

## Steps to Reproduce
### Command
```
../../fuzzer_load_png_name poc.bin
```
### Proof-of-Concept Input (if needed)
(attached: poc.bin)

## Suggested Fix Description
Before opening the file, check that file name is not `NULL`. If it is, free `current_chunk` if it was allocated (to avoid memory leaks) and return 1.
Also, in `error`, before closing `input`, check that `input` is not `NULL`.