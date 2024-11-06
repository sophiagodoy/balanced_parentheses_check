# Balanced Parentheses Checker

This C++ project implements an algorithm to check the balance of parentheses in mathematical expressions. The solution uses the **stack** data structure to ensure that each opening parenthesis has a corresponding closing parenthesis in the correct order.

## Features

- **Balance Check**: The program checks whether parentheses, square brackets, and curly braces are properly balanced in a given expression;
- **Stack Data Structure**: The stack is used to store opening parentheses and ensure that when a closing parenthesis is encountered, it matches the last opening parenthesis;
- **Input**: Users can provide an expression containing parentheses, brackets, and braces.

## How to Use

1. Compile the code in a C++ environment;
2. Pass an expression as input into the code;
3. The program will output whether the expression is valid or invalid based on the balance of parentheses.

## Example

Input: `{[(3+4)/2] + (5*2)}`

Output: `Valid expression`

Input: `{[(3+4)/2] + (5*2)`

Output: `Invalid expression`
