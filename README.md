Push Swap

Sorting a set of integers using predefined instructions on two stacks.
Introduction

The goal of this project is to create a program that sorts a set of integers using a set of instructions on two stacks, namely stack A and stack B. The program outputs a series of moves in push_swap instructions, aiming for an efficient sorting process with a limited set of actions.
Instructions

The possible actions include:

	pa (push A): Take the first element at the top of B and put it at the top of A. Do nothing if B is empty.
	pb (push B): Take the first element at the top of A and put it at the top of B. Do nothing if A is empty.
	sa (swap A): Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements.
	sb (swap B): Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements.
	ss: sa and sb at the same time.
	ra (rotate A): Shift all elements of stack A up by 1. The first element becomes the last one.
	rb (rotate B): Shift all elements of stack B up by 1. The first element becomes the last one.
	rr: ra and rb at the same time.
	rra (reverse rotate A): Shift all elements of stack A down by 1. The last element becomes the first one.
	rrb (reverse rotate B): Shift all elements of stack B down by 1. The last element becomes the first one.
	rrr : rra and rrb at the same time.

Output

The program outputs a series of moves to the standard output, each followed by a newline (\n). The printed set of moves should efficiently sort the input list using a limited number of actions.
Performance

This version of push_swap complies with the following performance benchmarks:

	Set of 3:
		Maximum: 2 actions

	Set of 5:
		Average: 7 actions
		Maximum: 10 actions

	Set of 100:
		Average: 587 actions
		Maximum: 665 actions
		Performance breakdown:
			Less than 700: 5 actions
			Less than 900: 4 actions
			Less than 1100: 3 actions
			Less than 1300: 2 actions
			Less than 1500: 1 action

	Set of 500:
		Average: 5205 actions
		Maximum: 5436 actions
		Performance breakdown:
			Less than 5500: 5 actions
			Less than 7000: 4 actions
			Less than 8500: 3 actions
			Less than 10000: 2 actions
			Less than 11500: 1 action
