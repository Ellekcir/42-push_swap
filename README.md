# Push Swap

## Introduction

The goal was to create a program that sorts a stack of integers with the smallest number of operations, using a set of instructions that manipulate two stacks. 

At first, I started out with **radix sort**, thinking it would be a simple and efficient solution. But soon, I realised it wasn't the best approach for this project. After some trial and error, I implemented **merge sort** using chunks, which turned out to be a much more efficient. 

## Objectives

This project has introduced:
- **Algorithm efficiency**: I had to make sure my solution sorted the integers in the least number of operations.
- **Algorithm complexity**: Understanding how sorting algorithms perform and how to optimise them for speed and memory.

## The Rules

Here are the rules for the project:

- We have **two stacks**, `a` and `b`. Stack `a` contains the integers to be sorted, and stack `b` is empty.
- We can use a set of operations to manipulate the stacks:
  - **swap** (sa, sb, ss)
  - **push** (pa, pb)
  - **rotate** (ra, rb, rr)
  - **reverse rotate** (rra, rrb, rrr)
- The challenge is to sort the integers in stack `a` using the fewest operations possible. 

## How to Run

To run the program, follow these steps:

1. Clone this repository to your local machine.
2. Navigate to the project folder.
3. Run the following command to compile the program:
    ```
    make
    ```

4. Once compiled, you can run the `push_swap` program with a list of integers as arguments:
    ```
    ./push_swap 5 3 8 1 6
    ```

    The program will output the list of instructions needed to sort the stack in the fewest operations.

5. You can also test the program with different sets of integers or invalid inputs to see how it handles them.

## Testing

I created multiple test cases to ensure that the program performs correctly and sorts efficiently. The tests covered:

- A random list of integers
- Lists already sorted
- Lists in reverse order
- Edge cases like invalid inputs or duplicate values

Here's an example of a test run:

```
$> ./push_swap 2 1 3 6 5 8
sa
pb
pb
pb
sa
pa
pa
pa
```

## Invalid Input Handling

If invalid inputs are provided, the program will return an error message:

```
$> ./push_swap 0 one 2 3
Error
```

## Testing Instructions

### Running Push_Swap with Arguments

To test the program with a large number of arguments and count the number of moves, use the following command:

```
ARG="-489168559 1623405915 190358334 1257360997 302289303 831459234 1664899502 -406019539 -1095434325 -169848056 -1422962681 70958194 669269243 1534133025 -835548601 -1761931065 1219492563 1887484815 -1108748302 777144735 274268383 489142513 1573519443 -228796469 -1631079236 -569616788 907548500 1428537474 -786945993 -139866847 2063032942 1382835917 -1950852512 -1687118481 -194512439 614633592 -634709675 1080841818 1437151262 -1001991190 1963794582 -276915548 443690245 292658081 -1752729264 264223719 1134248953 -1476616503 416379798 -202945498 1176627982 2074510434 1210895392 -1909301774 727244076 968791402 -1867994439 1750384538 -365220451 1995409735 1005513174 -1041455033 -1575879790 547493554 1234094515 1752489511 -1283516012 1556329078 1201910240 -1498298124 487174247 -516248388 -1415462777 1797888993 -1663175285 1132190634 -348533091 1319963188 -211746696 -157295522 1918243915 -693299771 -267284029 573648204 548506853 1754796797 -631596309 1579756789 984732314 1032182375"; ./push_swap $ARG | wc -l
```

### Running Push_Swap with the provided 42's checker_Mac
To test the program's sorting with the checker:

```
ARG="-489168559 1623405915 190358334 1257360997 302289303 831459234 1664899502 -406019539 -1095434325 -169848056 -1422962681 70958194 669269243 1534133025 -835548601 -1761931065 1219492563 1887484815 -1108748302 777144735 274268383 489142513 1573519443 -228796469 -1631079236 -569616788 907548500 1428537474 -786945993 -139866847 2063032942 1382835917 -1950852512 -1687118481 -194512439 614633592 -634709675 1080841818 1437151262 -1001991190 1963794582 -276915548 443690245 292658081 -1752729264 264223719 1134248953 -1476616503 416379798 -202945498 1176627982 2074510434 1210895392 -1909301774 727244076 968791402 -1867994439 1750384538 -365220451 1995409735 1005513174 -1041455033 -1575879790 547493554 1234094515 1752489511 -1283516012 1556329078 1201910240 -1498298124 487174247 -516248388 -1415462777 1797888993 -1663175285 1132190634 -348533091 1319963188 -211746696 -157295522 1918243915 -693299771 -267284029 573648204 548506853 1754796797 -631596309 1579756789 984732314 1032182375"; ./push_swap $ARG | ./checker_Mac $ARG
```
### Running Push_Swap with Small Arguments
You can also test with smaller sets of arguments:

```
ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_Mac $ARG
```
### Counting Number of Moves
To count the number of moves for small input:

```
ARG="1 5 2 4 3"; ./push_swap $ARG | wc -l
```
### Testing Edge Cases with Invalid Inputs
If you test with invalid inputs (such as non-integer values), it should display an error:

```
ARG="-1 1 0 94 -123"; ./push_swap $ARG | ./checker_Mac $ARG
```
### Sorted Inputs (No Moves)
For already sorted inputs, the program should display nothing:

```
ARG="1 2 3 4 5"; ./push_swap $ARG | ./checker_Mac $ARG
```
To test with multiple sorted numbers:

```
ARG="1 2 3 4 5"; ./push_swap $ARG | wc -l
```
### Edge Cases with Mixed Numbers
Test with mixed numbers (e.g., negative and positive values):

```
ARG="-1 1 0 94 -123"; ./push_swap $ARG | wc -l
```
### Push_Swap with Only One Argument
If the program is run with just one argument, it should not perform any actions and return no output:

```
./push_swap 42
./push_swap "42"
./push_swap 0 1 2 3
./push_swap "0 1 2 3"
```