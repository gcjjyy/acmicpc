#include <stdio.h>

char S[101];
int P[26];

int main() {
    scanf("%s", S);
    for(int i = 0; i <= 25; ++i) P[i] = -1;

    char *p = S;
    while(*p) {
        if(P[(*p) - 'a'] == -1) P[(*p) - 'a'] = p - S;
        p++;
    }

    for(int i = 0; i <= 25; ++i) printf("%d ", P[i]);
    printf("\n");

    return 0;
}