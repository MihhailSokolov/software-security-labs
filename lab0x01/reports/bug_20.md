# BUG-20
## Category
Iteration errors

## Description

Loops for drawing the circle have one iteration more than needed. They should go from `center - radius` to `center + radius` but should not include `center + radius`, so that they performed `2 * radius` iterations instead of `2 * radius + 1`.

## Affected Lines in the original program
In `circle.c:52` and `circle.c:75`

## Expected vs Observed
We expect program to draw a circle with diameter of `2 * radius`. We observe that it draws circle with diameter of `2 * radius + 1`.

## Steps to Reproduce

### Command

```
/circle test_imgs/ck.png ck_circle.png 30 30 30 000000
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Change `<=` to `<` in the above-mentioned for-loops.
