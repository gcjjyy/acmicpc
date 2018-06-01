#include <stdio.h>

char S[101];

int main() {
    scanf("%s", S);

    char *p = S;
    int count = 10;
    while(*p) {
        printf("%c", *p);
        p++;
        count--;

        if(count == 0) {
            count = 10;
            printf("\n");
        }
    }

    return 0;
}