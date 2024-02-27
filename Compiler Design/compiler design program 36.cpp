#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function to evaluate expression based on PEMDAS rule
int evaluateExpression(char *expression) {
    int result = 0,power;
    int num1, num2;
    char op;

    // Parse the expression and perform operations based on precedence
    sscanf(expression, "%d %c %d", &num1, &op, &num2);
    switch (op) {
        case '^':
            result = power(num1, num2); // Exponentiation
            break;
        case '*':
            result = num1 * num2; // Multiplication
            break;
        case '/':
            if (num2 != 0)
                result = num1 / num2; // Division
            else {
                printf("Error: Division by zero\n");
                exit(EXIT_FAILURE);
            }
            break;
        case '+':
            result = num1 + num2; // Addition
            break;
        case '-':
            result = num1 - num2; // Subtraction
            break;
        default:
            printf("Error: Invalid operator\n");
            exit(EXIT_FAILURE);
    }
    return result;
}

// Function to calculate exponentiation
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    char expression[100];

    // Input expression from user
    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);

    // Evaluate the expression based on PEMDAS rule
    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}

