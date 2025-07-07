# OpenMP Assignment

The objective here is to implement a parallel approach to merge sort.

## Project Structure
```.
├── bin
│   └── [Compiled Binaries]
├── Makefile
├── obj
│   └── [Object files]
├── README.md
└── src
    ├── main.c (has the test and verification)
    ├── mergesort.c  --> (This is the file that needs to be modified)
    └── mergesort.h
```
## Prerequisites
- gcc (with openmp)
- make
## Steps
- Fork this repository
- Work on the forked repo and commit to it
- In the code you will need to
    - Implement the standard Merge  function
    - Implement the parallel version of the given mergesort function.
- you will need to submit the link to your repo for evaluation

> Look for TODO: comments in the codebase

## Recommended Approach
- use `pragma omp task` to execute the recursion concurrently
- use `pragma omp taskwait` for the merge function, so that further tasks are blocked before the merge
  
> Change the `TEST_SIZE` macro to change the test case sizes and `SEED` to change the values in the array (main.c)

The `mergesort.c` file has 4 functions:
- `merge`: Merge function that will be used by serial and parallel impelmentations
- `merge_sort_sequential`: Example code for the serial merge sort.
- `merge_sort_parallel`: This function creates threads and calls the internal function.
- `merge_sort_parallel_internal`: This is where the core implementation logic lies.

## Steps to build and test
| Command            | Description                     |
| ------------------ | ------------------------------- |
| `make`             | build the release binary        |
| `make debug`       | build the debug binary          |
| `make run`         | build (if needed) + run release |
| `make rundebug`    | build (if needed) + run debug   |
| `make clean`       | delete objects & binaries       |
| `make rebuild`     | clean and rebuild from scratch  |

> NOTE: Debug mode just prints the arrays before and after sorting



## Expected Output

```
[ INFO ] Running Test with 10 elements:
[ DEBUG ] Original:             [66 40 81 41 12 58 21 40 35 43]
[ SUCCESS ] Serial Sort Verified
[ DEBUG ] Serial Sort:          [12 21 35 40 40 41 43 58 66 81]
[ SUCCESS ] Parallel Sort Verified
[ DEBUG ] Parallel Sort:        [12 21 35 40 40 41 43 58 66 81]
```


## References
- [pragma omp task](https://www.ibm.com/docs/en/zos/2.4.0?topic=processing-pragma-omp-task)
- [Merge Sort](https://www.geeksforgeeks.org/dsa/merge-sort/)
- [OpenMP Tasks](https://hpc2n.github.io/Task-based-parallelism/branch/master/task-basics-1/#task-construct)

If you have any doubts, or are stuck anywhere, please feel free to shoot me a mail at aadithyarao@gmail.com
All the best and good luck
