#include <stdio.h>

int C[10];
int max = 0;

int main() {
    int index;
    char s[10];
    scanf("%s", s);

    char *p = s;
    while(*p) {
        index = (*p) - '0';
        C[index]++;
        p++;
    }

    C[6] = C[9] = (C[6] + C[9] + 1) >> 1;

    for(int i = 0; i < 10; ++i) {
        if(C[i] > max) {
            max = C[i];
        }
    }

    printf("%d\n", max);

    return 0;
}