# BUG-4
## Category
Wrong operator

## Description

Comparison equals operator (`==`) is used instead of assignment operator (`=`).

## Affected Lines in the original program
In `circle.c:61` and `circle.c:84`

## Expected vs Observed
We expect program to draw full circle when all given arguments are correct. We observe that program draws only part of the circle.

## Steps to Reproduce

### Command

```
./circle test_imgs/ck.png white_circle.png 50 50 45 ffffff
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Use proper assignment operator (`=`) instead of equals operator (`==`) on those lines.
