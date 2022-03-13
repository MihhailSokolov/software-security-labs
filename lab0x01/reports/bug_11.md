# BUG-11
## Category
Command injection

## Description

An attacker can inject arbitrary commands because user input is used directly in system call: `stat -c output_name`.

## Affected Lines in the original program
In `solid.c:123`, `solid.c:124`, `solid.c:125`

## Expected vs Observed
We expect program to be secure and not allow for arbitrary command execution. We observe that user can execute any command through injection in the output file name.

## Steps to Reproduce

### Command

```
./solid "img.png; ls" 100 100 ffffff
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Use different ways to get the file size instead of providing a system call built from the user input.
For example, we can use:
```c
#include <sys/stat.h>
struct stat st;
stat(filename, &st);
int size = st.st_size;
printf("Size: %d\n", size);
```