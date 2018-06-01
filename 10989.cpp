#include <stdio.h>

int C[10001];

int main() {
    int N, a;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &a);
        C[a]++;
    }

    for(int i = 0; i <= 10000; ++i) {
        if(C[i]) {
            for(int j = 0; j < C[i]; ++j) printf("%d\n", i);
        }
    }

    return 0;
}