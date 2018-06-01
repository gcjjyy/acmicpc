#include <stdio.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int N;
int D[1000][3];
int rc[1000];
int gc[1000];
int bc[1000];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d%d%d", &rc[i], &gc[i], &bc[i]);
	}

	D[0][0] = rc[0];
	D[0][1] = gc[0];
	D[0][2] = bc[0];

	for(int i = 1; i < N; ++i) {
		D[i][0] = MIN(D[i-1][1], D[i-1][2]) + rc[i];
		D[i][1] = MIN(D[i-1][0], D[i-1][2]) + gc[i];
		D[i][2] = MIN(D[i-1][0], D[i-1][1]) + bc[i];
	}

	printf("%d\n", MIN(MIN(D[N-1][0], D[N-1][1]), D[N-1][2]));

	return 0;
}