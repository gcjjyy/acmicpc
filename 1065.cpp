#include <stdio.h>

int main() {
    int N;
    int count = 0;

    scanf("%d", &N);

    for(int i = 1; i <= N; ++i) {
        // 한수 구하기
        if(i < 100) count++;
        else {
            int num = i;
            int bef = (num % 10) - ((num / 10) % 10);
            int found = 0;
            while(num > 9) {
                int cur = (num % 10) - ((num / 10) % 10);
                if(cur != bef) {
                    found = 1;
                    break;
                }
                bef = cur;
                num /= 10;

            }
            if(!found) {
                count++;
            }
        }
    }

    printf("%d\n", count);

    return 0;
}