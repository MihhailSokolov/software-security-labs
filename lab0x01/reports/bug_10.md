# BUG-10
## Category
Iteration errors

## Description

Outer loop variable `i` must be incremented outside inner loop instead of inside of it. Otherwise, it reaches its maximum much quicker than supposed to.

## Affected Lines in the original program
In `rect.c:80`

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
Increment `i` as the last thing inside the outer loop. 
