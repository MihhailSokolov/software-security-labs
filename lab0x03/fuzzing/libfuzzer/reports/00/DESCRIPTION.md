# Bug 00
## Name
Memory safety violation (double free)

## Description
`current_chunk->chunk_data` is freed after it had already been freed. On `pngparser.c:648` the `current_chunk` is assigned to `idat_chunk`, hence `current_chunk->chunk_data` and `idat_chunk->chunk_data` point to the same memory location. `idat_chunk->chunk_data` is freed on line 640  and thus `current_chunk->chunk_data` is also freed. However, afterwards on line 702 `current_chunk->chunk_data` is freed again.

## Affected Lines
In `pngparser.c:702`

## Expected vs Observed
We expect the program not to violate memory safety which implies that it should not double free the memory. However, we observe that a memory region is tried to be freed twice which results in a segmentation fault.

## Steps to Reproduce
### Command
```
../../fuzzer_load_png poc.bin
```
### Proof-of-Concept Input (if needed)
(attached: poc.bin)

## Suggested Fix Description
Initialize `current_chunk->chunk_data` equal to `NULL`.
