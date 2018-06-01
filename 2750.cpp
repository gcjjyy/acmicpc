#include <stdio.h>

int A[1000];

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);

    for(int i = 0; i < N - 1; ++i) {
        for(int j = i + 1; j < N; ++j) {
            if(A[i] > A[j]) {
                int temp = A[i]; A[i] = A[j]; A[j] = temp;
            }
        }
    }

    for(int i = 0; i < N; ++i) printf("%d\n", A[i]);

    return 0;
}