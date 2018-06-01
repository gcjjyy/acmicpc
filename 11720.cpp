#include <stdio.h>

int N;
char nums[101];

int main() {
    scanf("%d", &N);
    scanf("%s", nums);

    int answer = 0;

    for(int i = 0; i < N; ++i) {
        answer += (int)(nums[i] - '0');
    }

    printf("%d\n", answer);
    return 0;
}