#include <stdio.h>
#define QSIZE 6500

int queue[QSIZE];
int qf = 0;
int qr = -1;
int qsz = 0;

void enq(int x) {
    qr = (qr + 1) % QSIZE;
    queue[qr] = x;
    qsz++;
}

int deq() {
    int ret = queue[qf];
    qf = (qf + 1) % QSIZE;
    qsz--;
    return ret;
}

int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    
    for(int i = 1; i <= N; ++i) enq(i);
    
    printf("<");
    while(qsz) {
        for(int i = 0; i < M-1; ++i) {
            enq(deq());
        }
        printf("%d", deq());
        if(qsz) printf(", ");
    }
    printf(">\n");
    
    return 0;
}
