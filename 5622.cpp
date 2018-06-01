#include <stdio.h>

int AtoN[26] = {
    2, 2, 2, // ABC
    3, 3, 3, // DEF
    4, 4, 4, // GHI
    5, 5, 5, // JKL
    6, 6, 6, // MNO
    7, 7, 7, 7, // PQRS
    8, 8, 8, // TUV
    9, 9, 9, 9 // WXYZ
};

char W[16];

int main() {
    int answer = 0;

    scanf("%s", W);

    char *p = W;
    while(*p) {
        answer += AtoN[*p - 'A'] + 1;
        p++;
    }

    printf("%d\n", answer);

    return 0;
}