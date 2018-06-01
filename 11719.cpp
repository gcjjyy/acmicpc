#include <stdio.h>

char buf[20000];

int main() {
    int len = 0;
    char ch = 0;
    while(ch != EOF) {
        ch = getchar();
        buf[len++] = ch;
    }
    buf[len-1] = 0;

    printf("%s\n", buf);

    return 0;
}