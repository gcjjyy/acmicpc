#include <stdio.h>

int T;
int x, y;

void solve() {
    int remain = y - x;
    int d = 1;
    int c = 0;
    while(remain) {
        if(2 * d <= remain) {
            c += 2;
            remain -= 2 * d;
            d++;
        }
        else {
            c += remain / d;
            remain -= (remain / d) * d;
            d--;
        }
    }

    printf("%d\n", c);
}

int main() {
    scanf("%d", &T);
    while(T--) {
        scanf("%d %d", &x, &y);
        solve();
    }
    return 0;
}