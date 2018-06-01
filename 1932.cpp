#include <stdio.h>

int N;
int W[500][500];
int D[500][500];

#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		for(int j = 0; j <= i; ++j) {
			scanf("%d", &W[i][j]);
		}
	}

	D[0][0] = W[0][0];
	for(int i = 1; i < N; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j > 0) D[i][j] = MAX(D[i-1][j], D[i-1][j-1]) + W[i][j];
			else D[i][j] = D[i-1][j] + W[i][j];
		}
	}

	int max = 0;
	for(int i = 0; i < N; ++i) {
		if(D[N-1][i] > max) max = D[N-1][i];
	}

	printf("%d\n", max);

	return 0;
}