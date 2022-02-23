# BUG-0
## Category
Potential stack overwrite

## Description

If `argv[1]` is longer than `OUTPUT_NAME_SIZE` then on `strcpy` a stack overwrite will happen.

## Affected Lines in the original program
In `solid.c:33`

## Expected vs Observed
We expect that if file length is too long, an error will be shown without program crashing. We observe that if the output file name argument is too long (>500), program crashes.

## Steps to Reproduce

### Command

```
./solid output_file111111...1111 100 100 ffffff # length of "output_file111111...1111" is greater than 500
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Use safer `strncpy(output_name, argv[1], OUTPUT_NAME_SIZE)` instead of `strcpy(output_name, argv[1])` to make sure that maximum length is taken into account when copying file name.
