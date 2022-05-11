# Bug 03
## Name
Memory safety violation (index out of bounds of array)

## Description
On line 410, the following assignment is performed - `img->px[idy * img->size_x + idx].red = plte_entries[palette_idx].red;`, however index `palette_idx` is actually larger than the length of array (`plte_entries`) for which it is used. This causes segmentation fault.

## Affected Lines
In `pngparser.c:410`

## Expected vs Observed
We expect the program not to violate memory safety which imples that all indexes that access arrays must be within the length of said arrays. However, we observe that an array is tried to be accessed with index larger than the length of array.

## Steps to Reproduce
### Command
```
../../size poc.bin
```
### Proof-of-Concept Input (if needed)
(attached: poc.bin)

## Suggested Fix Description
Check that index is not larger than the length of array before using it, i.e. add the following before line 410:
```c
if (palette_idx >= sizeof(plte_entries)/sizeof(plte_entries[0])) {
    return NULL;
}
```
