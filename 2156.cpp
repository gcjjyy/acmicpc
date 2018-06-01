#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int n;
int A[10000];
int D[10000];
int answer = 0;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}

	D[0] = A[0];
	D[1] = A[0] + A[1];
	D[2] = MAX(MAX(A[0] + A[2], A[1] + A[2]), D[1]);
	for(int i = 0; i < 3; ++i)
		if(D[i] > answer) answer = D[i];
	for(int i = 3; i < n; ++i) {
		D[i] = MAX(MAX(D[i-3] + A[i-1] + A[i], D[i-2] + A[i]), D[i-1]);
		if(D[i] > answer) answer = D[i];
	}

	printf("%d\n", answer);

	return 0;
}