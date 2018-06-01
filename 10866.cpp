#include <stdio.h>
#define DQSIZE 20000

int deque[DQSIZE];
int f = 0;
int r = DQSIZE-1;
int dqsz = 0;

void push_front(int x) {
    f = ((f - 1) + DQSIZE) % DQSIZE;
    deque[f] = x;
    dqsz++;
}

void push_back(int x) {
    r = (r + 1) % DQSIZE;
    deque[r] = x;
    dqsz++;
}

int pop_front() {
    if(!dqsz) return -1;
    int ret = deque[f];
    f = (f + 1) % DQSIZE;
    dqsz--;
    return ret;
}

int pop_back() {
    if(!dqsz) return -1;
    int ret = deque[r];
    r = ((r - 1) + DQSIZE) % DQSIZE;
    dqsz--;
    return ret;
}

int size() {
    return dqsz;
}

bool empty() {
    return dqsz == 0;
}

int front() {
    if(empty()) return -1;
    return deque[f];
}

int back() {
    if(empty()) return -1;
    return deque[r];
}

bool str_cmp(char *a, char *b) {
    while(*a || *b) {
        if(*a++ != *b++) return false;
    }
    return true;
}

int main() {
    int N, x;
    char inst[16];
    
    scanf("%d", &N);
    while(N--) {
        scanf("%s", inst);
        if(str_cmp(inst, "push_back")) {
            scanf("%d", &x);
            push_back(x);
        }
        else if(str_cmp(inst, "push_front")) {
            scanf("%d", &x);
            push_front(x);
        }
        else if(str_cmp(inst, "front")) {
            printf("%d\n", front());
        }
        else if(str_cmp(inst, "back")) {
            printf("%d\n", back());
        }
        else if(str_cmp(inst, "size")) {
            printf("%d\n", size());
        }
        else if(str_cmp(inst, "pop_front")) {
            printf("%d\n", pop_front());
        }
        else if(str_cmp(inst, "pop_back")) {
            printf("%d\n", pop_back());
        }
        else if(str_cmp(inst, "empty")) {
            printf("%d\n", empty() ? 1 : 0);
        }
    }
    return 0;
}
