# BUG-0
## Category
Potential stack overwrite

## Description

If `argv[1]` is longer than `OUTPUT_NAME_SIZE` then on `strcpy` a stack overwrite will happen.

## Affected Lines in the original program
In `solid.c:33`

## Expected vs Observed
We expect that if file length is too long, an error will be shown without program crashing. We observe that if the output file name argument is too long (>500), program might crash or worse - stack data can be overwritten.

## Steps to Reproduce

### Command

```
./solid output_file111111...1111 100 100 ffff # length of "output_file111111...1111" is greater than 500
```
### Proof-of-Concept Input (if needed)
(attached: poc.png)

## Suggested Fix Description
Before copying the `argv[1]` to `output_name`, the length of `argv[1]` must be checked and program must terminate in case that length is greater than `OUTPUT_NAME_SIZE`.
