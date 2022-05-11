# Bug 00
## Name
Memory safety violation (closing the file which hasn't been opened)

## Description
The program fails to open the file with `FILE *input = fopen(filename, "rb");` on line 555 and goes into `error` state which is fine. However, in the `error` state it tries to `fclose(input)` on line 703 even though `fopen` failed and `input` is 0. This leads to a segmentation fault.

## Affected Lines
In `pngparser.c:703`

## Expected vs Observed
We expect the program not to violate memory safety which implies that it should not close the file which hasn't been opened yet. However, we observe that the input file is tried to be closed before even if it hadn't been opened.

## Steps to Reproduce
### Command
```
../../size poc.bin
```
### Proof-of-Concept Input (if needed)
(attached: poc.bin)

## Suggested Fix Description
Free `input` only if it allocated, i.e.:
```c
if (input) {
    fclose(input);
}
```
instead of just `fclose(input)`