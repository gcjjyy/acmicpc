#include <stdio.h>

int Y[4];

int main() {
    int T = 3;
    while(T--) {
        scanf("%d%d%d%d", &Y[0], &Y[1], &Y[2], &Y[3]);

        int sum = 0;
        for(int i = 0; i < 4; ++i) {
            sum += Y[i];
        }

        switch(sum) {
            case 0: printf("D\n"); break;
            case 1: printf("C\n"); break;
            case 2: printf("B\n"); break;
            case 3: printf("A\n"); break;
            case 4: printf("E\n"); break;
        }
    }
    return 0;
}