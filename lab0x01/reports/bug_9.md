# BUG-9
## Category
Wrong operators/variables

## Description

Usage of variables `i` and `j` is wrong in `image_data`. `j` represents width and `i` represents height. Therefore they must be used as `image_data[j][i]` and not `image_data[i][j]` on lines 75-78. Otherwise, the rectangle will have wrong orientation or in some cases program might crash with segmentation fault because the array index is out of bounds.

## Affected Lines in the original program
In `rect.c:75`, `rect.c:76`, `rect.c:77`, `rect.c:78`

## Expected vs Observed
We expect program to draw a proper rectangle with correct orientation when all given arguments are correct. We observe that program draws rectangle with the wrong orientation.

## Steps to Reproduce

### Command

```
./rect test_imgs/ck.png white_rect.png 10 10 60 110 ffffff
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Swap `i` and `j` with each other on lines 75-78. 
