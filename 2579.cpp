#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int N;
int score[301];
int D[301][2];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) scanf("%d", &score[i]);

	D[0][0] = 0;
	D[0][1] = 0;
	D[1][0] = score[1];
	D[1][1] = 1;

	for(int i = 2; i <= N; ++i) {
		if(D[i-1][1] < 2 && D[i-1][0] + score[i] > D[i-2][0] + score[i]) {
			D[i][0] = D[i-1][0] + score[i];
			D[i][1] = D[i-1][1] + 1;
		}
		else {
			D[i][0] = D[i-2][0] + score[i];
			D[i][1] = 1;
		}
	}

	printf("%d\n", D[N][0]);
	return 0;
}