# BUG-7
## Category
Iteration errors

## Description

Inner loop variable `j` must be declared inside the outer loop, not outside it. Otherwise inner loop completes only one set of iterations i.e. goes from 0 to `width` only once instead of doing it `height` times to cover the whole image.

## Affected Lines in the original program
In `rect.c:62`

## Expected vs Observed
We expect program to draw a proper rectangle when all given arguments are correct. We observe that program draws only on the upper row of pixels.

## Steps to Reproduce

### Command

```
./rect test_imgs/ck.png white_rect.png 10 10 60 110 ffffff
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Initialize `j` the first thing inside the outer loop. 
