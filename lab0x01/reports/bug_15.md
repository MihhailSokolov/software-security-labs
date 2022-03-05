# BUG-15
## Category
Memory leak

## Description

After allocating memory for `palette`, that memory is never freed.

## Affected Lines in the original program
In `solid.c:16`

## Expected vs Observed
We expect program to free the allocated memory as soon as that memory is not needed. We observe that program doesn't free the portion of the memory which potentially can lead to filling up the RAM and crashing the program.

## Steps to Reproduce

### Command

```
???
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
After usage of `palette` is done, free that memory.
