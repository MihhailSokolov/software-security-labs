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
We can add the following sanitization check:
```c
if (strchr(argv[1], ';') != NULL) {
    goto error;
}
```
