#include <stdio.h>

long long D[21][21][21];

long long solve(int N, int L, int R) {
	long long &ret = D[N][L][R];
	if(ret != -1) return ret;

	if(N == 1) {
		if(L == 1 && R == 1) {
			return ret = 1;
		}
		else {
			return ret = 0;
		}
	}
	ret = solve(N-1, L-1, R) + solve(N-1, L, R-1) + (solve(N-1, L, R) * (N - 2));

	return ret;
}

int main() {
	int T;
	int N, L, R;
		    
	scanf("%d", &T);
	for(int i = 0; i < T; i++) {
		scanf("%d %d %d", &N, &L, &R);

		for(int j = 0; j < 21; j++)
		for(int k = 0; k < 21; k++)
		for(int l = 0; l < 21; l++)
			D[j][k][l] = -1;

		printf("%lld\n", solve(N, L, R));
	}		
	return 0;
}
