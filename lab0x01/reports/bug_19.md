# BUG-19
## Category
Unchecked system call returning code

## Description

After storing the final image, a program doesn't check that it was actually successfully stored.

## Affected Lines in the original program
In `checkerboard.c:129`, `circle.c:93`

## Expected vs Observed
We expect program to check that it correctly saved the image. We observe that program doesn't check if the image was saved or not, it simply exits.

## Steps to Reproduce

### Command

```
???
```
### Proof-of-Concept Input (if needed)
(Not needed)

## Suggested Fix Description
Change `store_png(output_name, img, palette, 2)` to:
```c
if (store_png(output_name, img, palette, 2)) {
    free(img->px);
    free(img);
    printf("Error saving the image\n");
    return 1;
}
```
