#include <stdio.h>

int stack[100100];
int sp;
char answer[200000];
int ap;

void push(int X) {
    stack[sp++] = X;
    answer[ap++] = '+';
}

int pop() {
    answer[ap++] = '-';
    return stack[--sp];
}

int main() {
    int N, n, m = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; ++i) {
        scanf("%d", &n);

        if(m <= n) {
            while(m <= n) {
                push(m++);
            }
            pop();
        }
        else {
            if(sp == 0) {
                printf("NO\n");
                return 0;
            }
            int ret = pop();
            if(ret != n) {
                printf("NO\n");
                return 0;
            }
        }
    }

    for(int i = 0; i < ap; ++i) printf("%c\n", answer[i]);
    return 0;
}