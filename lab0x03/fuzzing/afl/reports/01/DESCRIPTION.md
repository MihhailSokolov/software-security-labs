# Bug 01
## Name
Memory safety violation (double free)

## Description
`current_chunk->chunk_data` is freed after it had already been freed. On `pngparser.c:648` the `current_chunk` is assigned to `idat_chunk`, hence `current_chunk->chunk_data` and `idat_chunk->chunk_data` point to the same memory location. `idat_chunk->chunk_data` is freed on line 657  and thus `current_chunk->chunk_data` is also freed. However, afterwards on line 710 `current_chunk->chunk_data` is freed again.

## Affected Lines
In `pngparser.c:710`

## Expected vs Observed
We expect the program not to violate memory safety which implies that it should not double free the memory. However, we observe that a memory region is tried to be freed twice which results in a segmentation fault.

## Steps to Reproduce
### Command
```
../../size poc.bin
```
### Proof-of-Concept Input (if needed)
(attached: poc.bin)

## Suggested Fix Description
Don't free the memory second time, i.e. comment out or remove line `pngparser.c:710`. Since line 710 is the only statement in the if condition, the whole condition (lines 709-711) can be removed or commented out.
