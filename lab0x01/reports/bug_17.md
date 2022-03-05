# BUG-17
## Category
Iteration errors

## Description

Off-by-one errors - loops iterate from `i = 0` and `j = 0` until `i <= img->size_y` and `j <= img->size_x`, however, `i = img->size_y` and `j = img->size_x` are already out of bounds of the image.

## Affected Lines in the original program
In `filter.c:118` and `filter.c:119`

## Expected vs Observed
We expect program to work properly given correct arguments. We observe that program crashes with an error because the loops when outside of the bounds of the image.

## Steps to Reproduce

### Command

```
./filter test_imgs/ck.png neg_ck.png negative
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Replace `<=` in the loop conditions with `<`.
