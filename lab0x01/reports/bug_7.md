# BUG-7
## Category
Incorrect usage of loop variables.

## Description

Inner loop variable `j` must be declared inside the outer loop, not outside it. Otherwise inner loop completes only one set of iterations i.e. goes from 0 to `width` only once instead of doing it `height` times to cover the whole image. Also, usage of variables `i` and `j` is wrong in `image_data`. `j` represents width and `i` represents height. Therefore they must be used as `image_data[j][i]` and not `image_data[i][j]` on lines 75-78. Otherwise, the rectangle will have wrong orientation or in some cases program might crash with segmentation fault because the array index is out of bounds. Additionally, outer loop variable `i` must be incremented outside inner loop instead of inside of it. Otherwise, it reaches its maximum much quicker than supposed to.

## Affected Lines in the original program
In `rect.c:62`, `rect.c:75`, `rect.c:76`, `rect.c:77`, `rect.c:78` and `rect.c:80`

## Expected vs Observed
We expect program to draw a proper rectangle when all given arguments are correct. We observe that program draws only diagonal line instead of full rectangle.

## Steps to Reproduce

### Command

```
./rect test_imgs/ck.png white_rect.png 10 10 60 110 ffffff
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Initialize `j` the first thing inside the outer loop, increment `i` as the last thing inside the outer loop, and swap `i` and `j` with each other on lines 75-78. 
