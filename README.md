<img src="assets/rope.png" height="50" />

## Climber

Based on the original [research paper](https://www.cs.rit.edu/usr/local/pub/jeh/courses/QUARTERS/FP/Labs/CedarRope/rope-paper.pdf)

A study of the rope data structure and comparitive analysis aginst the traditional string implementation. An attempt to understand the data structure itself(its variations) and the optimizations it offers. To create a benchmark and collect data for visual representation for fun and because its cool.

## Build

```console
$ make
## or
$ gcc -g rope.c rope_test.c -o rope.out
```

## Libraries Used

## Test

On running the program with [t8.shakespear.txt](https://ocw.mit.edu/ans7870/6/6.006/s08/lecturenotes/files/t8.shakespeare.txt) the whole file traversal took 0.420s average compared to cat 0.200s.
