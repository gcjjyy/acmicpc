#include <stdio.h>

int N;

typedef struct {
    char W[51];
    int len;
} Word;

Word W[20000];
Word M[20000];
int wcount = 0;

int str_len(char *p) {
    int len = 0;
    while(*p) {
        len++;
        p++;
    }
    return len;
}

bool str_cmp(char *a, char *b) {
    while(*a && *b) {
        if(*a++ != *b++) return false;
    }
    return true;
}

void msort(int l, int r) {
    int i;
    if (l == r) return;
    int m = (l + r) >> 1;

    msort(l, m);
    msort(m+1, r);

    int index = l;
    int lp = l;
    int rp = m+1;
    while(index <= r) {
        if(lp > m) {
            M[index++] = W[rp++];
        }
        else if(rp > r) {
            M[index++] = W[lp++];
        }
        else {
            if(W[lp].len < W[rp].len) {
                M[index++] = W[lp++];
            }
            else if(W[lp].len > W[rp].len) {
                M[index++] = W[rp++];
            }
            else {
                int result = -1;
                for(i = 0; i < W[lp].len; ++i) {
                    if(W[lp].W[i] < W[rp].W[i]) {
                        result = 0;
                        break;
                    }
                    else if(W[lp].W[i] > W[rp].W[i]) {
                        result = 1;
                        break;
                    }
                }
                if(result <= 0)
                    M[index++] = W[lp++];
                else
                    M[index++] = W[rp++];
            }
        }
    }

    for(i = l; i <= r; ++i) W[i] = M[i];
}

int main() {
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%s", W[wcount].W);
        W[wcount].len = str_len(W[wcount].W);
        wcount++;
    }

    msort(0, N-1);

    printf("%s\n", W[0].W);
    for(int i = 1; i < N; ++i) {
        if(W[i].len == W[i-1].len && str_cmp(W[i].W, W[i-1].W)) continue;
        printf("%s\n", W[i].W);
    }
}