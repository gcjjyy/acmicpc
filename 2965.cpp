#include <stdio.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
    int P[3];
    scanf("%d%d%d", &P[0], &P[1], &P[2]);
    for(int i = 0; i < 2; ++i) {
        for(int j = i + 1; j < 3; ++j) {
            if(P[i] > P[j]) {
                int temp = P[i];
                P[i] = P[j];
                P[j] = temp;
            }
        }
    }

    printf("%d\n", MAX(P[1] - P[0], P[2] - P[1]) - 1);
    return 0;
}