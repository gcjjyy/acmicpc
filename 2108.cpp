#include <stdio.h>

int A[500001];
int M[500001];
int C[8002];
int D[500001];
int dc = 0;

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
    double SUM = 0;
    int maxCount = 0;
    int maxCountNum = 0;

    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        SUM += A[i];
        C[A[i] + 4000]++;
    }

    for(int i = 0; i < 8002; ++i) {
        if(C[i] > maxCount) {
            maxCount = C[i];
            maxCountNum = i - 4000;
        }
    }

    for(int i = 0; i < 8002; ++i) {
        if(C[i] == maxCount) D[dc++] = i - 4000;
    }

    if(dc > 1) {
        for(int i = 0; i < dc - 1; ++i) {
            for(int j = i + 1; j < dc; ++j) {
                if(D[i] > D[j]) {
                    int temp = D[i]; D[i] = D[j]; D[j] = temp;
                }
            }
        }

        maxCountNum = D[1];
    }

    msort(0, N - 1);

    printf("%.0lf\n", (SUM / N));
    printf("%d\n", A[(N - 1) / 2]);
    printf("%d\n", maxCountNum);
    printf("%d\n", A[N-1] - A[0]);

    return 0;
}