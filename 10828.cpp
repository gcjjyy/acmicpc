#include <stdio.h>

int N;

/*
push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

int stack[11000];
int sp = 0;
int X;

int main() {
    scanf("%d", &N);

    char inst[8];
    for(int i = 0; i < N; ++i) {
        scanf("%s", inst);
        if(inst[0] == 'p' && inst[1] == 'u') {
            scanf("%d", &X);
            stack[sp++] = X;
        }
        else if(inst[0] == 'p' && inst[1] == 'o') {
            if(sp == 0) printf("-1\n");
            else printf("%d\n", stack[--sp]);
        }
        else if(inst[0] == 's' && inst[1] == 'i') {
            printf("%d\n", sp);
        }
        else if(inst[0] == 'e' && inst[1] == 'm') {
            printf("%d\n", (sp == 0) ? 1 : 0);
        }
        else if(inst[0] == 't' && inst[1] == 'o') {
            if(sp == 0) printf("-1\n");
            else printf("%d\n", stack[sp-1]);
        }
    }

    return 0;
}