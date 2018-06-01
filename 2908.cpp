#include <stdio.h>

int reverse(int n) {
    int r = 0;
    while(n > 0) {
        r = r * 10 + (n % 10);
        n /= 10;
    }

    return r;
}

int main() {
    int A, B;
    scanf("%d %d", &A, &B);

    int rA = reverse(A);
    int rB = reverse(B);

    if(rA > rB) printf("%d\n", rA);
    else printf("%d\n", rB);

    return 0;
}