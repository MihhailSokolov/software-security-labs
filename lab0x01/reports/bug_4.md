# BUG-4
## Category
Stack buffer overflow/underflow

## Description

`argv[7]` doesn't exist because there are only 7 arguemtns while code tries to access it. Hence Out-of-Bounds error happens.

## Affected Lines in the original program
In `circle.c:29` and `circle.c:30`

## Expected vs Observed
We expect program to work properly when all given arguments are correct. We observe that program crashes with Segmentation Fault

## Steps to Reproduce

### Command

```
./circle test_imgs/ck.png white_circle.png 50 50 45 ffffff
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Index 6 must be used on those lines - `argv[6]`
