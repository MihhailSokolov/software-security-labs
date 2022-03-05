# BUG-16
## Category
Temporal safety vialation

## Description

A memory needed for the data structure pixel is not being allocated before the structure is used.

## Affected Lines in the original program
In `filter.c:108`

## Expected vs Observed
We expect program to allocate the memory it needs. We observe that program doesn't allocate the memory needed for data structure it uses which can lead to the crash of the program.

## Steps to Reproduce

### Command

```
./filter test_imgs/ck.png neg_ck.png negative
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Allocate the memory required for `pixel` struct when instantiating it.
