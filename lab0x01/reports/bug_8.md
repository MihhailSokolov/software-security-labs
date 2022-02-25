# BUG-8
## Category
Heap overfow/underflow

## Description

Not enough memory is allocated to the new image and when code tries to write data to where it thinks the new image is, the program crashes with segmentation fault.

## Affected Lines in the original program
In `resize.c:48`

## Expected vs Observed
We expect program to work properly when all given arguments are correct. We observe that program crashes with segmentation fault.

## Steps to Reproduce

### Command

```
./resize test_imgs/ck.png big_ck.png 2.0
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
The proper amount of memory that must be allocated is the amount it takes for signle pixel times the number of pixels. Hence, `new_img->px = malloc(n_pixels + sizeof(struct pixel));` must be replaced with `new_img->px = malloc(n_pixels * sizeof(struct pixel));`.
