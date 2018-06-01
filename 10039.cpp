#include <stdio.h>

int S[5];

int main() {
    scanf("%d %d %d %d %d", &S[0], &S[1], &S[2], &S[3], &S[4]);

    int total = 0;
    for(int i = 0; i <= 4; ++i) {
        total += (S[i] >= 40) ? S[i] : 40;
    }

    printf("%d\n", total / 5);

    return 0;
}