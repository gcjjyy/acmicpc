#include <stdio.h>

int T;
char A[51];
int sp = 0;
char *p;

int main() {
    scanf("%d", &T);
    while(T--) {
        sp = 0;
        scanf("%s", A);
        p = A;
        int error = 0;
        while(*p) {
            if(*p == '(') sp++;
            else if(*p == ')') {
                sp--;
                if(sp < 0) {
                    error = 1;
                    break;
                }
            }
            p++;
        }

        if(error || sp != 0) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}