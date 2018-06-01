#include <stdio.h>

int T;
char S[81];

int main() {
    scanf("%d", &T);
    while(T-- > 0) {
        scanf("%s", S);

        int count = 0;
        int cur = 0;
        int total = 0;

        char *p = S;
        while(*p) {
            if(*p == 'O') {
                count++;
                cur += count;
            }
            else {
                total += cur;
                cur = 0;
                count = 0;
            }
            p++;
        }
        total += cur;

        printf("%d\n", total);
    }

    return 0;
}