# BUG-14
## Category
Unchecked system call returning code

## Description

After allocating memory for `palette`, a program doesn't check that the memory was actually successfully allocated. In case the memory wasn't allocated, it will result in the segmentation fault.

## Affected Lines in the original program
In `solid.c:16`, `solid.c:65-68`

## Expected vs Observed
We expect program to check that it operates under correct assumptions i.e. when it thinks that memory was allocated, the memory must be allocated. We observe that program doesn't really validate its assumptions and can operate undre false assumptions which results in a crash.

## Steps to Reproduce

### Command

```
???
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
After allocating memory for `palette`, a check must be made to ensure that allocation was indeed successful:
```c
if (!palette) {
    printf("Couldn't allocate memory for palette");
    return 1;
}
```
