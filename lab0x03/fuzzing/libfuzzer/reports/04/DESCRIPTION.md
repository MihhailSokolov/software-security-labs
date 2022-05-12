# Bug 04
## Name
Memory safety violation (accessing inaccessible memory)

## Description
The program fails to open the file with `FILE *output = fopen(filename, "wb");` on line 999 when filename is `NULL`. It tries to read memory with address `0x00`.

## Affected Lines
In `pngparser.c:999`

## Expected vs Observed
We expect the program not to violate memory safety which implies that it should not read the memory it does not have access to. However, we observe that the program violates that and tries to read memory with address `0x00`.

## Steps to Reproduce
### Command
```
../../fuzzer_store_png_name poc.bin
```
### Proof-of-Concept Input (if needed)
(attached: poc.bin)

## Suggested Fix Description
Before opening the file, check that file name is not `NULL`. If it is, return 1.