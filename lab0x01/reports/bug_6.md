# BUG-6
## Category
Type error

## Description

Developer forgot to use pointer address instead of using pointer value for variable `end_ptr`.

## Affected Lines in the original program
In `rect.c:34`

## Expected vs Observed
We expect program to work properly when all given arguments are correct. We observe that program crashes with Segmentation Fault.

## Steps to Reproduce

### Command

```
./rect test_imgs/ck.png white_rect.png 10 10 60 110 ffffff
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Use `&end_ptr` instead of `end_ptr` on that line.
