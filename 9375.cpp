#include <stdio.h>

int dp[31][31];
char typeNames[30][21];
int items[30];
int typeCount;
int n;

bool str_cmp(char *a, char *b) {
    while(*a || *b) {
        if(*a++ != *b++) return false;
    }
    return true;
}

void str_cpy(char *dst, char *src) {
    while(*src) {
        *dst++ = *src++;
    }
    *dst = 0;
}

int main() {
    int T;
    char name[21];
    char type[21];
    
    for(int i = 0; i < 31; ++i) dp[i][0] = 1;
    for(int i = 1; i < 31; ++i) {
        for(int j = 1; j < 31; ++j) {
            dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    
    scanf("%d", &T);
    while(T--) {
        typeCount = 0;
        
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) {
            scanf("%s%s", name, type);
            bool found = false;
            for(int j = 0; j < typeCount; ++j) {
                if(str_cmp(typeNames[j], type)) {
                    found = true;
                    items[j]++;
                    break;
                }
            }
            if(!found) {
                str_cpy(typeNames[typeCount], type);
                items[typeCount] = 1;
                typeCount++;
            }
        }

        long long answer = 1;
        for(int i = 0; i < typeCount; ++i) {
            answer *= (items[i] + 1);
        }

        printf("%lld\n", answer - 1);
    }
    return 0;
}
