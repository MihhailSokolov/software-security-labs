# BUG-22
## Category
Arithmetic overflow/underflow

## Description

When resizing an image with certain factor, the width and height of the resized image are not checked to see if they are still withing the bounds of `unsigned short` which is used for storing height and width. If `factor * width` or `factor * width` is larger than `USHRT_MAX` then the arithmetic overflow occurs.

## Affected Lines in the original program
In `resize.c.c:33` and `resize.c:34`

## Expected vs Observed
We expect program to check if it can avtually produce the image of the size a user wants and if the resulting image is too big, program should abort. We observe that program doesn't check the new dimenstions and width and height overflow resulting is a smaller image.

## Steps to Reproduce

### Command

```
./resize test_imgs/ck.png big_ck.png 1100
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Before assigning the new dimenstions, perform a check:
```c
if (height * factor > USHRT_MAX || width * factor > USHRT_MAX) {
    return 1;
}
```
