#include <stdio.h>

int T;
int M, N, x, y;

int gcd(int a, int b) {
    int tmp;
    while(b) {
        tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d %d", &M, &N, &x, &y);

        int _lcm = lcm(M, N);

        while(x != y && x <= _lcm) {
            if(x < y) x += M;
            else y += N;
        }

        if(x > _lcm) printf("-1\n");
        else printf("%d\n", x);
    }

    return 0;
}