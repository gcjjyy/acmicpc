#include <stdio.h>

int N, M;
int MAP[1000][1000];
int dp[1000][1000];

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
int max = 0;

/*
int main()
{
  int n,m;
  
  scanf("%d%d ",&n,&m);
  int i,j,s;
  for(i=0;i<n;i++)scanf("%s", map[i]);
  for(i=0;i<m;i++)if(map[0][i]=='1'){dp[0][i]=1;max=1;}
  for(i=0;i<n;i++)if(map[i][0]=='1'){dp[i][0]=1;max=1;}
  for(i=1;i<n;i++)
  {
    for(j=1;j<m;j++)
    {
      if(map[i][j]=='1')
      {
        dp[i][j]=1+MIN(MIN(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
        max=MAX(max,dp[i][j]);
      }
    }
  }
  printf("%d",max*max);
  return 0;
}
*/

void solve() {
    max = 0;

    for(int i = 0; i < N; ++i) { dp[i][0] = MAP[i][0]; if(MAP[i][0] == 1) max = 1; }
    for(int i = 0; i < M; ++i) { dp[0][i] = MAP[0][i]; if(MAP[0][i] == 1) max = 1; }

    for(int i = 1; i < N; ++i) {
        for(int j = 1; j < M; ++j) {
            if(MAP[i][j]) {
                int tl = dp[i-1][j-1];
                int l = dp[i][j-1];
                int t = dp[i-1][j];
                dp[i][j] = MIN(tl, MIN(l, t)) + 1;
                if(max < dp[i][j]) max = dp[i][j];
            }
        }
    }

    printf("%d\n", max*max);
}

int main() {
    char data[1001];
    scanf("%d%d", &N, &M);

    for(int i = 0; i < N; ++i) {
        scanf("%s", data);
        int index = 0;

        for(char *p = data; *p; ++index, p++) {
            if(data[index] == '1') MAP[i][index] = 1;
            else MAP[i][index] = 0;
        }
    }

    solve();
    return 0;
}