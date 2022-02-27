# BUG-13
## Category
Arithmetic overflow/underflow

## Description

The circle can wrap around the image if it is larger than the image or it is centered in a way that circle has to go beyond the image. This results in a weird lines instead of a proper circle.

## Affected Lines in the original program
In `circle.c:52-54`, `circle.c:61-62`, `circle.c:75-77`, `circle.c:84-85`

## Expected vs Observed
We expect program to check that it can draw a proper circle with the given parameters and inform the user if it can't. We observe that program tries to place a circle on the image even if it is not possible and crashes sometimes.

## Steps to Reproduce

### Command

```
./circle test_imgs/ck.png ck_circle.png 20 20 30 000000
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Before drawing the circle need to check that `center_x + radius < width`, `center_x - radius >= 0`, `center_y + radius < height`, and `center_y - radius >= 0`.
