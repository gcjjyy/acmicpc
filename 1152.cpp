#include <stdio.h>

char A[1000001];

int main() {
    int count = 1;

    int len = 0;
    char ch = 0;
    while(ch != EOF && ch != '\n') {
        ch = getchar();
        A[len++] = ch;
    }
    A[len-1] = 0;

    if(A[0] == ' ') count--;
    if(A[len-2] == ' ') count--;

    char *p = A;
    while(*p) {
        if(*p == ' ') count++;
        p++;
    }

    printf("%d\n", count);

    return 0;
}