#include <stdio.h>
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

int N;
int W[500];
int SUM[500];
int D[500][500];

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 0; i < N; ++i) {
			scanf("%d", &W[i]);
			SUM[i] = W[i] + ((i > 0) ? SUM[i-1] : 0);
			D[i][i] = 0;
		}

		for(int i = 1; i < N; ++i) {
			for(int j = 0; j < N-i; ++j) {
				D[j][j+i] = (1 << 30);
				for(int k = j; k < j+i; ++k) {
					D[j][j+i] = MIN(D[j][j+i], D[j][k] + D[k+1][j+i] + SUM[j+i] - (j > 0 ? SUM[j-1] : 0));
				}
			}
		}

		printf("%d\n", D[0][N-1]);
	}
	return 0;
}