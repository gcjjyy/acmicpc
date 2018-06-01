#include <stdio.h>

int A[8];

int main() {
    int ascending = 0;
    int descending = 0;
    for(int i = 0; i <= 7; ++i) {
        scanf("%d", &A[i]);

        if(i && A[i] > A[i-1]) ascending = 1;
        if(i && A[i] < A[i-1]) descending = 1;
    }

    if(ascending && descending) printf("mixed\n");
    else if(ascending) printf("ascending\n");
    else printf("descending\n");

    return 0;
}