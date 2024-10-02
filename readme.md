# Push_swap

> A project designed to teach sorting algorithms and their complexity by implementing a stack-based sorting program in C.

## Overview

The **Push_swap** project challenges you to sort data on a stack using a limited set of instructions with the fewest possible operations. The goal is to write a C program that efficiently sorts a list of integers and outputs the sequence of sorting instructions.

## Features

- Implements various stack-based sorting algorithms.
- Handles random positive and negative integers with no duplicates.
- Utilizes a minimal number of operations.
- Provides a `checker` program to verify the sorting sequence.

## Instructions

### Stack Operations

The following operations are available for manipulating two stacks, `a` and `b`:

- `sa`: Swap the first two elements of stack `a`.
- `sb`: Swap the first two elements of stack `b`.
- `ss`: Swap the first two elements of both stacks simultaneously.
- `pa`: Push the top element of stack `b` to stack `a`.
- `pb`: Push the top element of stack `a` to stack `b`.
- `ra`: Rotate stack `a` (shift all elements up by one).
- `rb`: Rotate stack `b`.
- `rr`: Rotate both stacks simultaneously.
- `rra`: Reverse rotate stack `a` (shift all elements down by one).
- `rrb`: Reverse rotate stack `b`.
- `rrr`: Reverse rotate both stacks simultaneously.

### Example

Consider sorting the integers `2 1 3 6 5 8`. An example sequence of operations might be:
```text 
ra
pb
ra
ra
pb
rra
pa
rra
rra
pa
```

### Usage

1. Compile the program using the provided `Makefile`:
```bash
   make

    Run the push_swap program with a list of integers:
```
```bash

./push_swap 2 1 3 6 5 8
```

Verify the sorting result with the checker program (Bonus):

```bash

ARG="2 1 3 6 5 8"; ./push_swap $ARG | ./checker $ARG
``` 