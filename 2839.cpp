#include <stdio.h>

int N;
int dp[5001];

#define INF 2000
#define min(a, b) (((a) < (b)) ? (a) : (b))

void solve() {
    dp[0] = INF;
    dp[1] = INF;
    dp[2] = INF;
    dp[3] = 1;
    dp[4] = INF;
    dp[5] = 1;
    
    // dp[i] = i KG을 나르는데 필요한 최소 개수
    for(int i = 6; i <= N; ++i) {
        dp[i] = min(dp[i-3], dp[i-5]) + 1;
    }

    if(dp[N] >= INF) dp[N] = -1;
    printf("%d\n", dp[N]);
}

int main() {
    scanf("%d", &N);

    solve();

    return 0;
}