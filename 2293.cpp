#include <stdio.h>

#define MAX_N 100
#define MAX_K 10000

int n, k;
int V[MAX_N];
int D[MAX_K + 1];

int main() {
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; ++i) scanf("%d", &V[i]);

	D[0] = 1;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j <= k; ++j) {
			if(j >= V[i]) {
				D[i] += D[j-V[i]];
			}
		}
	}

	printf("%d\n", D[k]);

	return 0;
}