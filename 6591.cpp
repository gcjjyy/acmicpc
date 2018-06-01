#include <stdio.h>

int main() {
    int n, k;
    do {
        scanf("%d%d", &n, &k);
        if(!n && !k) break;
        unsigned long long answer = 1;
        
        if(n - k < k) k = n - k;
        
        for(int i = 1; i <= k; ++i) {
            answer *= n--;
            answer /= i;
        }
        
        printf("%lld\n", answer);
    }while(n || k);
    return 0;
}
