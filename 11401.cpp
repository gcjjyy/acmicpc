#include <stdio.h>
#define MOD 1000000007

typedef unsigned long long ull;

ull factorial(ull n) {
    ull ret = 1;
    while(n) {
        ret = (ret * n) % MOD;
        n--;
    }
    return ret;
}

ull pow(ull m, ull n) {
    if(n == 0) return 1;
    if(n == 1) return m;
    
    if(n&1 == 1) {
        return ((pow(m, n / 2) % MOD) * (pow(m, n / 2 + 1) % MOD)) % MOD;
    }
    else {
        return ((pow(m, n / 2) % MOD) * (pow(m, n / 2) % MOD)) % MOD;
    }
}

ull modInv(ull k) {
    return pow(k, MOD - 2);
}

int main() {
    int N, K;
    scanf("%d%d", &N, &K);
    
    // (N!) / (K!(N-K)!)
    ull nfact = factorial(N);
    ull kfact = factorial(K);
    ull nkfact = factorial(N-K);
    
    printf("%lld\n", (nfact * modInv((kfact * nkfact) % MOD)) % MOD);
    return 0;
}
