# BUG-22
## Category
Arithmetic overflow/underflow

## Description

Blur filter can accept radii larger than the image, including radii like INT_MAX+1 which lead to arithmetic overflow.

## Affected Lines in the original program
In `filter.c:52`

## Expected vs Observed
We expect program to check that the given arguments are correct and abort otherwise. We observe that program doesn't check the arguments and tries to work with incorrect arguments which lead to incorrect result.

## Steps to Reproduce

### Command

```
./filter test_imgs/ck.png blur_ck.png blur 2147483648
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Perform the following check:
```c
if (radius < 0 || (radius > img->size_x && radius > img->size_y)) {
    return;
}
```
