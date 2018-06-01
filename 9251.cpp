#include <stdio.h>
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

char A[1002];
char B[1002];
int D[1002][1002];

int str_len(char *p) {
	int len = 0;
	while(*p) {
		len++;
		p++;
	}
	return len;
}

int main() {
	int la, lb;
	scanf("%s%s", &A[1], &B[1]);
	A[0] = ' ';
	B[0] = ' ';
	la = str_len(A);
	lb = str_len(B);

	for(int i = 1; i < la; ++i) {
		for(int j = 1; j < lb; ++j) {
			if(A[i] == B[j]) {
				D[i][j] = D[i-1][j-1] + 1;
			}
			else {
				D[i][j] = MAX(D[i-1][j], D[i][j-1]);
			}
		}
	}

	printf("%d\n", D[la-1][lb-1]);

	return 0;
}