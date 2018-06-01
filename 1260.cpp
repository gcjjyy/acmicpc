#include <stdio.h>

int G[1000][1000];
int N, S;
char visit[1000];
char visit2[1000];

int queue[15000];
int qf = 0, qr = -1, qsz = 0;
void enq(int x) {
    qr = (qr + 1) % 15000;
    queue[qr] = x;
    qsz++;
}
int deq() {
    int ret = queue[qf];
    qf = (qf + 1) % 15000;
    qsz--;
    return ret;
}

void DFS(int n) {
    visit[n] = 1;
    printf("%d ", n+1);
    for(int i = 0; i < N; ++i) {
        if(G[n][i] && !visit[i]) DFS(i);
    }
}

void BFS() {
    visit2[S-1] = 1;
    enq(S-1);
    while(qsz) {
        int X = deq();
        
        printf("%d ", X+1);
        
        for(int i = 0; i < N; ++i) {
            if(G[X][i] && !visit2[i]){
                visit2[i] = 1;
                enq(i);
            }
        }
    }
}

int main() {
    int M, a, b;
    scanf("%d%d%d", &N, &M, &S);
    while(M--) {
        scanf("%d%d", &a, &b);
        G[a-1][b-1] = 1;
        G[b-1][a-1] = 1;
    }
    
    DFS(S-1);
    printf("\n");
    BFS();
    printf("\n");
    
    return 0;
}
