#include <stdio.h>
#define MOD 10007

int dp[1001][1001];

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    
    for(int i = 0; i <= N; ++i) dp[i][0] = 1;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= K; ++j) {
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % MOD;
        }
    }
    
    printf("%d\n", dp[N][K]);
    
    return 0;
}
