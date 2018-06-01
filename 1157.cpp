#include <stdio.h>

char W[1000001];
char _A[26];
int C[26];
int gap;

int main() {
    scanf("%s", W);

    gap = 'a' - 'A';

    for(int i = 0; i <= 25; ++i) _A[i] = 'A' + i;

    char *p = W;
    while(*p) {
        if((*p) >= 'a') (*p) -= gap;
        C[(*p) - 'A']++;
        p++;
    }

    // Select Sort
    for(int i = 0; i <= 24; ++i)
        for(int j = i+1; j <= 25; ++j) {
            if(C[i] < C[j]) {
                int temp = C[i];
                C[i] = C[j];
                C[j] = temp;

                char t = _A[i];
                _A[i] = _A[j];
                _A[j] = t;
            }
        }

    if(C[0] == C[1]) printf("?\n");
    else printf("%c\n", _A[0]);

    return 0;
}