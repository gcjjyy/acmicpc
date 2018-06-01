#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int N;
int D[10000001];

int dp(int n) {
	int &ret = D[n];
	if(ret != -1) return ret;

	if(n == 1) return 0;

	ret = 1 << 30;

	if((n % 3) == 0) {
		ret = MIN(dp(n / 3), ret);
	}
	if((n & 1) == 0) {
		ret = MIN(dp(n / 2), ret);
	}
	ret = MIN(dp(n-1), ret);
	ret += 1;

	return ret;
}

int main() {
	scanf("%d", &N);
	for(int i = 0; i < 10000001; ++i) D[i] = -1;
	printf("%d\n", dp(N));
	return 0;
}