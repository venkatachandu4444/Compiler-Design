#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Global variables
char *input;
int pos;

// Function prototypes
int expression();
int term();
int factor();
void error();

// Function to consume the next character in the input
void consume(char expected) {
    if (*input == expected)
        input++, pos++;
    else
        error();
}

// Function to handle syntax errors
void error() {
    fprintf(stderr, "Syntax error at position %d\n", pos);
    exit(EXIT_FAILURE);
}

// Function to parse an expression
int expression() {
    int result = term();
    while (*input == '+' || *input == '-') {
        char op = *input;
        consume(op);
        int value = term();
        if (op == '+')
            result += value;
        else
            result -= value;
    }
    return result;
}

// Function to parse a term
int term() {
    int result = factor();
    while (*input == '*' || *input == '/') {
        char op = *input;
        consume(op);
        int value = factor();
        if (op == '*')
            result *= value;
        else
            result /= value;
    }
    return result;
}

// Function to parse a factor
int factor() {
    int result;
    if (isdigit(*input)) {
        result = *input - '0';
        consume(*input);
    } else if (*input == '(') {
        consume('(');
        result = expression();
        consume(')');
    } else
        error();
    return result;
}

int main() {
    // Input expression
    input = "(2+3)*4-6/2";
    pos = 0;

    // Parse the expression and print the result
    int result = expression();
    printf("Result: %d\n", result);

    return 0;
}

