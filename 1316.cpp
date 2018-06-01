#include <stdio.h>

int N;
char W[100][101];
int P[26];
int answer;

int main() 
{
    answer = 0;

    scanf("%d", &N);
    for(int i = 0; i <= N-1; ++i) {
        scanf("%s", W[i]);
    }

    for(int i = 0; i <= N-1; ++i) {
        for(int j = 0; j <= 25; ++j) P[j] = -1;

        int found = 0;
        for(int j = 0; W[i][j]; ++j) {
            if(P[W[i][j] - 'a'] == -1) {
                P[W[i][j] - 'a'] = j;
            }
            else {
                if(P[W[i][j] - 'a'] == j-1) {
                    P[W[i][j] - 'a'] = j;
                }
                else {
                    found = 1;
                    break;
                }
            }
        }

        if(!found) {
            answer++;
        }
    }

    printf("%d\n", answer);

    return 0;
}