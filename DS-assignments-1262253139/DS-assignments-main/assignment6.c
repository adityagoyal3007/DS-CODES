#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 20

int top = -1;   
char stack[max];

int isfull() {
    if (top == max - 1) {
        return 1;
    } else {
        return 0;
    }
}

int isempty() {
    if (top == -1) {
        return 1;
    } else {
        return 0;
    }
}

void push(char x) {
    if (!isfull()) {
        top += 1;
        stack[top] = x;     // Push the ch onto the stack
    } else {
        printf("Stack Overflow\n"); // Stack is full
    }
}

char pop() {
    char ch;

    if (!isempty()) {
        ch = stack[top];
        top -= 1;
        return ch;
    } else {
        return '\0';
    }
}

int isp(char tkn) { // In-Stack Precedence

    if (tkn == '+' || tkn == '-') {
        return 1;
    }

    if (tkn == '*' || tkn == '/') {
        return 2;
    }

    if (tkn == '^') {
        return 3;
    }

    if (tkn == '(') {
        return 0;
    }

    return -1;
}

int icp(char tkn) { // Incoming Precedence

    if (tkn == '+' || tkn == '-') {
        return 1;
    }

    if (tkn == '*' || tkn == '/') {
        return 2;
    }

    if (tkn == '^') {
        return 4;
    }

    if (tkn == '(') {
        return 5;
    }

    return -1;
}

void infixToPostfix(char inexp[max], char postexp[max]) {

    int k = 0;
    int i = 0;
    char tkn = inexp[i];

    while (tkn != '\0') {

        // Check if tkn is an operand
        if (isalnum(tkn)) {
            postexp[k] = inexp[i];
            k++;
        }

        else {

            if (tkn == '(') {
                push('(');
            }

            else {

                if (tkn == ')') {

                    while ((tkn = pop()) != '(') {
                        postexp[k] = tkn;
                        k++;
                    }
                }

                else {

                    while (top != -1 &&
                           isp(stack[top]) >= icp(tkn)) {

                        postexp[k] = pop();
                        k++;
                    }

                    push(tkn);
                }
            }
        }

        i++;
        tkn = inexp[i];
    }

    while (top != -1) {
        postexp[k] = pop();
        k++;
    }

    postexp[k] = '\0';
}

int main() {

    char infix[max];
    char postexp[max];

    printf("\nEnter an infix expression: ");

    if (scanf("%s", infix) != 1) {
        return 1;
    }

    infixToPostfix(infix, postexp);

    printf("Infix Expression: %s\n", infix);
    printf("Postfix Expression: %s\n", postexp);

    return 0;
}