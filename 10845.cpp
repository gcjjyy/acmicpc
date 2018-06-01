#include <stdio.h>

#define QUEUE_SIZE 20000

int queue[QUEUE_SIZE];
int f, r = -1, sz;

int N;

void enqueue(int x) {
    r = (r + 1) % QUEUE_SIZE;
    queue[r] = x;
    sz++;
}

int dequeue() {
    int ret = queue[f];
    f = (f + 1) % QUEUE_SIZE;
    sz--;
    return ret;
}

int main() {
    char inst[16];
    int x;
    scanf("%d", &N);
    while(N--) {
        scanf("%s", &inst);
        if(inst[0] == 'p' && inst[1] == 'u') {
            scanf("%d", &x);
            enqueue(x);
        }
        else if(inst[0] == 'p' && inst[1] == 'o') {
            if(sz > 0) printf("%d\n", dequeue());
            else printf("-1\n");
        }
        else if(inst[0] == 's' && inst[1] == 'i') {
            printf("%d\n", sz);
        }
        else if(inst[0] == 'e' && inst[1] == 'm') {
            printf("%d\n", sz == 0 ? 1 : 0);
        }
        else if(inst[0] == 'f' && inst[1] == 'r') {
            if(sz > 0) printf("%d\n", queue[f]);
            else printf("-1\n");
        }
        else if(inst[0] == 'b' && inst[1] == 'a') {
            if(sz > 0) printf("%d\n", queue[r]);
            else printf("-1\n");
        }
    }
    return 0;
}
