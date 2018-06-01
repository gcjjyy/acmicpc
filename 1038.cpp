#include <stdio.h>

int N;

int main() {
	scanf("%d", &N);

	int n = 0;
	int k = 0;
	while() {
		if(isDecrease(n)) {
			k++;
			if(k == N) {
				printf("%d\n", n);
				return 0;
			}
		}
		n++;
	}

	printf("-1\n");

	return 0;
}