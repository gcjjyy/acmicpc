#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);

    int dt = 6;
    int count = 1;
    int check = 1;
    while(check < N) {
        count++;
        check += dt;
        dt += 6;
    }

    printf("%d\n", count);
    return 0;
}