Author          : Ruyi Ding
Created         : September 3, 2018
Last Modified   : September 4, 2018

Affiliation          : Georgia Institute of Technology


Description
-------------

This program can be used to allocate a specific memory space for a certain size matrix, generate a random matrix with elements in (0.0, 10.0). Its core function is to do multiplication for two matrixes, using the most simply method with a time complexity:
$$
O(n^3)
$$
If there are lack of memory space, the function will go wrong. You have to modify the size of matrixes in main function in matrixMutiply.c. The other functions are written in matrix.c with it's head file matrix.h. As a result, if you want to use the functions in matrix.c, you should include matrix.h and compile and link them.


Installation
------------

To install, first compile matrix.c and matrixMutiply.c.

```shell
gcc -c matrix.c -o matrix.o
```

```shell
gcc -c matrixMutiply.c -o matrixMutiply.o
```

Then link the output files

```shell
gcc matrix.o matrixMutiply.o -o matrixMutiply.out
```

Execution
-----------

Assuming your executable is called "matrixMutiply.out", run it using

```shell
./matrixMutiply.out
```


