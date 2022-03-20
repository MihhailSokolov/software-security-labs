# BUG-2
## Category
Temporal safety violation

## Description

In case of an error `img` is freed twice.

## Affected Lines in the original program
In `checkerboard.c:91`

## Expected vs Observed
We expect a program to shutdown gracefully in case of an error. We observe that program crashes when tries to free the `img` second time.

## Steps to Reproduce

### Command

```
/checkerboard bw.png 100 100 10 ffffff 000000
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Remove `free(img)` on line 91 of `checkerboard.c`.
