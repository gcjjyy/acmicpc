#include <stdio.h>

int A[1000000];
int M[1000000];

void msort(int l, int r) {
    if(l == r) return;

    int m = (l + r) >> 1;

    msort(l, m);
    msort(m + 1, r);

    int index = l;
    int li = l;
    int ri = m + 1;
    while(index <= r) {
        if(li > m) {
            M[index++] = A[ri++];
        }
        else if(ri > r) {
            M[index++] = A[li++];
        }
        else {
            if(A[li] < A[ri]) M[index++] = A[li++];
            else M[index++] = A[ri++];
        }
    }

    for(int i = l; i <= r; ++i) A[i] = M[i];
}

int main() {
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) scanf("%d", &A[i]);

    msort(0, N - 1);

    for(int i = 0; i < N; ++i) printf("%d\n", A[i]);

    return 0;
}