# BUG-21
## Category
Arithmetic overflow/underflow

## Description

For-loops use `short` for indexes `i` and `j` when traversing image. If image's height or width is larger than 65535, it will cause arithmetic overflow.

## Affected Lines in the original program
In `filter.c.c:22` and `filter.c:23`

## Expected vs Observed
We expect program to be able to handle large images. We observe that if the image is too large, an arithmetic overflow occurs and the filter is applied to only small portion of the image.

## Steps to Reproduce

### Command

```
??? # Wasn't able to generate image large enough
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Use `int` instead of `short` when initializing loop variables.
