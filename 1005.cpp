#include <stdio.h>
#define MAX_N 1000

int T;
int N, K;
int D[MAX_N];
int W;

int main() {
    int from, to;

    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &K);
        for(int i = 0; i < N; ++i) scanf("%d", &D[i]);
        for(int i = 0; i < K; ++i) {
            scanf("%d%d", &from, &to);
            --from; --to;
        }
        scanf("%d", &W);

        
    }
    return 0;
}