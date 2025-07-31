#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top == MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (top == -1) {
        return '\0';  // Stack empty
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isp(char op) {
    // In-stack precedence
    switch (op) {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '^': return 5;  // Assuming ^ is exponent
        case '(': return 0;
        default: return -1;
    }
}

int icp(char op) {
    // Incoming precedence
    switch (op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return -1;
    }
}

int isOperand(char ch) {
    return (ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

void convert(char exp[]) {
    int i = 0;
    char item, x;
    push('(');            // Step 1: push '(' to stack
    int length = 0;
    while (exp[length] != '\0') length++;
    exp[length] = ')';    // add ')' to end of expression
    exp[length + 1] = '\0';

    while (!isEmpty()) {
        item = exp[i++];
        if (item == '\0') break;  // safety check

        if (isOperand(item)) {
            printf("%c", item);   // Step 3: operand to postfix
        }
        else if (item == '(') {
            push(item);           // Step 4: push '('
        }
        else if (item == ')') {
            // Step 8 and 9: pop until '('
            while ((x = pop()) != '(') {
                printf("%c", x);
            }
        }
        else {
            // Step 5, 6, 7: operator handling with precedence
            x = pop();
            while (isp(x) >= icp(item)) {
                printf("%c", x);
                x = pop();
            }
            push(x);
            push(item);
        }
    }
}

int main() {
    char exp[100];
    printf("Enter the infix expression (without spaces): ");
    scanf("%s", exp);

    printf("Postfix expression: ");
    convert(exp);
    printf("\n");

    return 0;
}

