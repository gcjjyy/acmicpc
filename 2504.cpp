#include <stdio.h>

char A[31];
char *p;

int stack[100];
int sp;

// (()[[]])([])

int main() {
    scanf("%s", A);
    p = A;
    int score = 0;
    while(*p) {
        switch(*p) {
            case '(':
            case '[':
                stack[sp++] = *p;
            break;
            case ')':
                if(stack[sp-1] == '(') score += 2;
            break;
            case ']':
                if(stack[sp-1] == '[') score += 3;
            break;
        }
        p++;
    }
    return 0;
}