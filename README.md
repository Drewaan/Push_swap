push_swap

![Language](https://img.shields.io/badge/Language-C-blue.svg)
![School](https://img.shields.io/badge/School-42%20Network-black.svg)
![Optimization](https://img.shields.io/badge/Optimization-Min%20Moves-orange)

## 📖 About push_swap

`push_swap` is a computational challenge that involves sorting a stack of unique integers. The difficulty lies in the extremely limited set of available operations and the strict requirement to find the most optimal solution (i.e., the one requiring the **minimum number of moves**).

The sorting process must be achieved by manipulating two stacks:
1.  **Stack A**: The initial unsorted list, and the final destination for the sorted list.
2.  **Stack B**: An auxiliary stack used for temporary storage and manipulation.

The final program output is simply a sequence of operations (e.g., `ra pb sa`) that, when executed by a separate checker program, successfully sorts Stack A.

## 📌 The Operations

The sorting process is limited to the following 11 operations, which are the only instructions allowed in the final output:

| Op. | Name | Description |
| :--- | :--- | :--- |
| **sa** | swap a | Swap the first two elements of stack A. |
| **sb** | swap b | Swap the first two elements of stack B. |
| **ss** | swap swap | Execute `sa` and `sb` at the same time. |
| **pa** | push a | Take the top element of B and put it on top of A. |
| **pb** | push b | Take the top element of A and put it on top of B. |
| **ra** | rotate a | Shift all elements of A up by one (the first element becomes the last). |
| **rb** | rotate b | Shift all elements of B up by one. |
| **rr** | rotate rotate | Execute `ra` and `rb` at the same time. |
| **rra** | reverse rotate a | Shift all elements of A down by one (the last element becomes the first). |
| **rrb** | reverse rotate b | Shift all elements of B down by one. |
| **rrr** | reverse rotate rotate | Execute `rra` and `rrb` at the same time. |

## 💡 Algorithmic Strategy

Due to the extreme requirement for optimization (minimizing the number of moves), a simple sorting algorithm is insufficient. The final solution employs a dynamic, adaptive strategy:

1.  **Indexing:** The input numbers are first converted into a simple index range (0 to N-1) for easier comparison and manipulation, regardless of their original value.
2.  **Small Set Solvers:** Dedicated, hard-coded, and fully optimized solvers are used for very small lists (3, 4, and 5 elements) to guarantee the absolute minimum moves.
3.  **Large Set Solver (Radix/Chunking):** For larger lists (500+ elements), an index-based **Radix Sort** variant or a chunking strategy is implemented to efficiently push elements to Stack B, sort them, and push them back to Stack A.

## 🛠️ Usage and Compilation

### Compilation

The project is compiled using the standard `Makefile`:

```bash
make
```
### Execution

The push_swap program takes a list of unique integers as command-line arguments and prints the sequence of sorting operations to standard output.

```bash

# Example: Sorting the list 2 1 3 6 5 8
./push_swap 2 1 3 6 5 8
# Output: pb pb ra sa rra pa pa pa
```

### Verification (Piping to Checker)

To verify that the output sequence correctly sorts the list (requires a separate checker program, usually provided by the school):

```bash

ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
# Output: OK (if sorted) or KO (if not sorted)
