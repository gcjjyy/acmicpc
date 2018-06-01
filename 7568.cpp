#include <stdio.h>

int N;
int x[50];
int y[50];
int score[50];

int main() {
	scanf("%d", &N);
	for(int i = 0; i < N; ++i) {
		scanf("%d%d", &x[i], &y[i]);
		score[i] = 1;
	}

	for(int i = 0; i < N; ++i) {
		for(int j = 0; j < N; ++j) {
			if(x[i] < x[j] && y[i] < y[j]) score[i]++;
		}
	}

	for(int i = 0; i < N; ++i) {
		printf("%d ", score[i]);
	}
	printf("\n");

	return 0;
}