Based on the original research paper

Ref - [https://www.cs.rit.edu/usr/local/pub/jeh/courses/QUARTERS/FP/Labs/CedarRope/rope-paper.pdf](https://www.cs.rit.edu/usr/local/pub/jeh/courses/QUARTERS/FP/Labs/CedarRope/rope-paper.pdf)

## Climber

A study of the rope data structure and comparitive analysis aginst the traditional string implementation. An attempt to understand the data structure itself(its variations) and the optimizations it offers. To create a benchmark and collect data for visual representation for fun and because its cool.

## Build

```console
$ make
## or
$ gcc -o rope.out rope.c
```

## Libraries Used

## Test

On running the program with [t8.shakespear.txt](https://ocw.mit.edu/ans7870/6/6.006/s08/lecturenotes/files/t8.shakespeare.txt) the whole file traversal took 0.420s average compared to cat 0.200s.
