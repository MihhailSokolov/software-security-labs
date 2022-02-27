# BUG-12
## Category
Heap overflow/underflow

## Description

If width or heigh is not multiple of the square width, then some memory outside of the image gets overwritten.

## Affected Lines in the original program
In `checkerboard.c:113-122`

## Expected vs Observed
We expect program to work with images of all sizes. We observe that a program crashes whenever the image size is not a multiple of the square size.

## Steps to Reproduce

### Command

```
./checkerboard bw.png 100 95 10 ffffff 000000
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Need to check if the place where square ends is still within the image i.e. current width + square width < total width
