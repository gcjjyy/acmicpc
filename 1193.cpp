#include <stdio.h>

int main() {
    long long X;
    scanf("%lld", &X);

    long long a = 1, b = 1, c = 1, d = 1;
    int R = 1;
    while(d + c <= X) {
        d += c;
        ++c;
        ++b;
        R = 1 - R;
    }

    long long gap = X - d;
    b -= gap;
    a += gap;

    if(R) printf("%lld/%lld\n", b, a);
    else printf("%lld/%lld\n", a, b);

    return 0;
}