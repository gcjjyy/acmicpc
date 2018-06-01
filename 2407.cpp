#include <stdio.h>

class BigInteger
{
public:
    int length;
    char buf[100];
    BigInteger() {
        length = 1;
        for(int i = 0; i < 100; ++i) buf[i] = 0;
    }
    
    void put() {
        for(int i = length - 1; i >= 0; --i) printf("%d", buf[i]);
        printf("\n");
    }
    
    void set(unsigned long long value) {
        length = 0;
        while(value) {
            buf[length++] = value % 10;
            value /= 10;
        }
    }
    
    void add(BigInteger &rhs) {
        int upper = 0;
        int i = 0;
        int digit = 0;
        while(i < this->length || i < rhs.length || upper) {
            digit = this->buf[i] + rhs.buf[i] + upper;
            if(digit >= 10) {
                digit -= 10;
                upper = 1;
            }
            else {
                upper = 0;
            }
            this->buf[i] = digit;
            i++;
            if(i >= length) length = i;
        }
    }
};

int n, m;
BigInteger dp[101][101];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i <= n; ++i) dp[i][0].set(1);
    
    for(int i = 1; i <= n; ++i) {
        for(int j = 1; j <= m; ++j) {
            dp[i][j].add(dp[i-1][j-1]);
            dp[i][j].add(dp[i-1][j]);
        }
    }
    
    dp[n][m].put();
    return 0;
}
