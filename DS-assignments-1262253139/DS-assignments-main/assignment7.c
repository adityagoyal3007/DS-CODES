#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAX 50

int stack[MAX];
int top = -1;

int isfull()
{
    return top == MAX - 1;
}

int isempty()
{
    return top == -1;
}

void push(int x)
{
    if (!isfull())
    {
        top++;
        stack[top] = x;
    }
    else
    {
        printf("Stack Overflow\n");
    }
}

int pop()
{
    if (!isempty())
    {
        int x = stack[top];
        top--;
        return x;
    }
    else
    {
        printf("Stack Underflow\n");
        return 0;
    }
}

int evaluate(char exp[]) 
{
    int i = 0; //
    int a, b, result; //( a is op1 , b is op2)
    char ch;

    while (exp[i] != '\0') 
    {
        ch = exp[i];   //current chr will be stored in ch
        if (isdigit(ch)) 
        {
          push(ch - '0'); //char to int then push in stack
        }
        else if (isalpha(ch))
        {
            int value;  //variable for storing current value of variable
            printf("Enter value of %c: ", ch);
            scanf("%d", &value);
            push(value);
        }
        else
        {
            b = pop();
            a = pop();

            switch (ch)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    if (b == 0)
                    {
                        printf("Division by zero error\n");
                        return 0;
                    }
                    result = a / b;
                    break;

                case '^':
                    result = (int)pow(a, b);
                    break;

                default:
                    printf("Invalid operator\n");
                    return 0;
            }

            push(result);
        }

        i++;
    }

    return pop();
}

int main()
{
    char exp[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%49s", exp);

    result = evaluate(exp);

    printf("Result = %d\n", result);

    return 0;
}
