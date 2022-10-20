# CS258 Example: C++
This assignment is written in C++, and tested with make and [Catch2](https://github.com/catchorg/Catch2).

### The assignment
#### Part 1 - Chapter 6
- Write a function that uses a stack to test whether a given string is a palindrome. Exercise 14 asked you to write an algorithm for such a function.
- Design and implement a postfix calculator. Use the algorithm given in this chapter to evaluate postfix expressions as entered into the calculator. Use only the operators +, −, *, and /. Assume that the postfix expressions are syntactically correct.


#### Part 2 - Chapter 7
- Write an implementation of the ADT stack that uses a resizable array to represent the stack items. Anytime the stack becomes full, double the size of the array. Maintain the stack’s bottom entry at the beginning of the array. Title your class `ArrayStackRS` and Inherit from the `ArrayStack` implementation that the book provides (code included in repo).  In addition to the code necessary to implement the growing of the array, add a `getSize` method that returns the current size of the array.
- The ADT stack lets you peek at its top entry without removing it. For some applications of a stack, you need to also peek at the entry beneath the top entry without removing it. Let’s name such an operation `peek2`. If `peek2` fails because the stack contains fewer than two entries, it should throw an exception. Create a custom exception that inherits from the base class exception and use it in the `peek2` method. Write a link-based implementation of the ADT stack that includes both `peek` and `peek2`. Call the class `StackPeek2` and inherit from `LinkedStack`.  


### Setup command
N/A

### Run command
`make test`

### Other test commands
If you want to run just one of the tests, you can use `make test<x>` and replace
`<x>` with the test number.

### Notes
- Don't push the executable files to the repo.   The easy way to do this is to run `make clean` before pushing.
- **Do not modify the Makefile, or anything in the tests directory unless specified in the instructions**
- If you want to test your code outside of the unit testing environment, you can create a new `.cpp` file that has a `main()` function.
