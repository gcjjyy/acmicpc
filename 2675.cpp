#include <stdio.h>

int T;
int R;
char S[21];
char S2[161];

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %s", &R, S);

        char *p = S;
        char *p2 = S2;
        while(*p) {
            for(int i = 1; i <= R; ++i)
                *p2++ = *p;
            p++;
        }
        *p2 = 0;
        printf("%s\n", S2);
    }
    return 0;
}