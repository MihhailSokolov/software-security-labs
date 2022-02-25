# BUG-3
## Category
Stack buffer overflow/underflow

## Description

If `argv[4]` is longer than `ARG_SIZE` then on `strcpy` a stack overwrite will happen.

## Affected Lines in the original program
In `filter.c:225`

## Expected vs Observed
We expect that if file length is too long, an error will be shown without program crashing. We observe that if the output file name argument is too long (>255), program crashes.

## Steps to Reproduce

### Command

```
./filter in_img.png out_img.png blur 11111...11111 # length of "11111...11111" is greater than 255
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Use safer `strncpy(arg, argv[4], ARG_SIZE)` instead of `strcpy(arg, argv[4])` to make sure that maximum length is taken into account when copying argument.
