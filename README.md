# MiniCompilerCPP - Arithmetic Expression Evaluator

## Overview
MiniCompilerCPP is a simple command-line calculator that evaluates arithmetic expressions entered by the user. It supports the four basic arithmetic operations:

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

as well as parentheses for grouping.

The program converts infix expressions to postfix notation (Reverse Polish Notation) using the shunting-yard algorithm and then evaluates the postfix expression to produce the result.

---

## Features

- Supports multi-digit integers and floating-point numbers (e.g., `12`, `3.14`)
- Handles operator precedence (`*` and `/` have higher precedence than `+` and `-`)
- Supports parentheses for explicit grouping
- Converts infix expressions to postfix expressions internally
- Evaluates postfix expressions using a stack-based algorithm

---

## How to Use

1. Compile the program using a C++ compiler (e.g., `g++`):

   ```bash
   g++ -o MiniCompilerCPP MiniCompilerCPP.cpp
   ```

2. Run the compiled executable:

   ```bash
   ./MiniCompilerCPP
   ```

3. When prompted, enter an arithmetic expression, for example:

   ```
   Enter arithmetic expression: (3 + 4) * 5 - 6 / 2
   ```

4. The program will output the postfix form of the expression and then the evaluated result:

   ```
   Postfix: 3 4 + 5 * 6 2 / -
   Result: 31
   ```

---

## Limitations and Notes

- Currently, the program **does not support unary minus** (negative numbers) natively. Expressions like `-5 + 3` may not evaluate correctly.
- Expressions should be well-formed with balanced parentheses.
- Division by zero is not explicitly checked and may cause runtime errors.
- Whitespace in the expression is ignored and can be used freely.
- Input validation and error handling are minimal.

---

## Possible Improvements

- Support unary minus for negative numbers.
- Add robust error handling for invalid expressions, unbalanced parentheses, and division by zero.
- Extend the evaluator to support more operators and functions (e.g., exponentiation, modulus).
- Add support for variables and assignment statements.

---

## Code Structure

- `precedence(char op)`: Returns the precedence level of the operator.
- `isOperator(char c)`: Checks if a character is an operator.
- `infixToPostfix(const string& expr)`: Converts an infix expression to postfix notation.
- `evaluatePostfix(const string& postfix)`: Evaluates a postfix expression and returns the numeric result.
- `main()`: Reads the expression from the user, converts it, evaluates it, and outputs results.

---

## License

This project is open source and free to use.
