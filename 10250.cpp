#include <stdio.h>

int main() {
    int T, H, W, N;
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d %d", &H, &W, &N);
        N--;
        int a = N % H + 1;
        int b = N / H + 1;
        printf("%d%02d\n", a, b);
    }
    return 0;
}