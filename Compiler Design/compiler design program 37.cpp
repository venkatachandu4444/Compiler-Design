#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a three address code instruction
typedef struct {
    char result[20]; // Result variable
    char op[10];     // Operator
    char arg1[20];   // First argument
    char arg2[20];   // Second argument
} TACInstruction;

// Function to generate Three Address Code (TAC) for a given expression
void generateTAC(char *expression) {
    char *token = strtok(expression, " "); // Tokenize the expression

    TACInstruction tac;

    // Parse tokens and generate TAC
    while (token != NULL) {
        // Assuming expression is in the form: result = arg1 op arg2
        strcpy(tac.result, token);
        token = strtok(NULL, " ");
        strcpy(tac.op, token);
        token = strtok(NULL, " ");
        strcpy(tac.arg1, token);
        token = strtok(NULL, " ");
        strcpy(tac.arg2, token);

        // Print TAC instruction
        printf("%s = %s %s %s\n", tac.result, tac.arg1, tac.op, tac.arg2);

        // Get next token
        token = strtok(NULL, " ");
    }
}

int main() {
    char expression[100];

    printf("Enter the expression (e.g., result = arg1 op arg2): ");
    fgets(expression, sizeof(expression), stdin);

    // Remove newline character if present
    if (expression[strlen(expression) - 1] == '\n') {
        expression[strlen(expression) - 1] = '\0';
    }

    // Generate Three Address Code (TAC)
    printf("Three Address Code (TAC):\n");
    generateTAC(expression);

    return 0;
}

