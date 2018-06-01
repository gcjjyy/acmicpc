#include <stdio.h>

int M, N;
int map[500][500];

int main() {
	scanf("%d%d", &M, &N);
	for(int i = 0; i < M; ++i) {
		for(int j = 0; j < N; ++j) {
			scanf("%d", &map[i][j]);
		}
	}

	return 0;
}