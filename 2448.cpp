/*                   (1, 24)
                       *                        
                      * *                       
                     *****                      
                    *     *                     
                   * *   * *                    
                  ***** *****                   
                 *           *                  
                * *         * *                 
               *****       *****                
              *     *     *     *               
             * *   * *   * *   * *              
(12, 12)    ***** ***** ***** *****  (12, 35)
           *                       *            
          * *                     * *           
         *****                   *****          
        *     *                 *     *         
       * *   * *               * *   * *        
      ***** *****             ***** *****       
     *           *           *           *      
    * *         * *         * *         * *     
   *****       *****       *****       *****    
  *     *     *     *     *     *     *     *   
 * *   * *   * *   * *   * *   * *   * *   * *  
***** ***** ***** ***** ***** ***** ***** *****
*/
#include <stdio.h>
#include <stdlib.h>

int N;
char *A;

#define ARRAY_WIDTH (N * 2 + 1)

void T(int t, int b, int l, int r) {
    int mh = (b + t) >> 1;
    int mw = (r + l) >> 1;

    if(b - t + 1 == 3) {
        A[t*ARRAY_WIDTH+mw] = '*';
        A[(t+1)*ARRAY_WIDTH+(mw-1)] = '*';
        A[(t+1)*ARRAY_WIDTH+(mw+1)] = '*';
        A[(t+2)*ARRAY_WIDTH+(mw-2)] = '*';
        A[(t+2)*ARRAY_WIDTH+(mw-1)] = '*';
        A[(t+2)*ARRAY_WIDTH+(mw)] = '*';
        A[(t+2)*ARRAY_WIDTH+(mw+1)] = '*';
        A[(t+2)*ARRAY_WIDTH+(mw+2)] = '*';
    }
    else {
        T(t, mh, (l + mw) >> 1, (mw + r) >> 1);
        T(mh + 1, b, l, mw);
        T(mh + 1, b, mw + 1, r);
    }
}

int main() {
    scanf("%d", &N);
    A = (char *)malloc(N * ARRAY_WIDTH);
    for(int i = 0; i < N * ARRAY_WIDTH; ++i) A[i] = ' ';
    for(int i = 0; i < N; ++i) A[i*ARRAY_WIDTH+(2*N)] = '\n';
    A[N * ARRAY_WIDTH - 1] = 0;

    T(0, N-1, 0, N*2-1);
    printf("%s\n", A);
    free(A);
    return 0;
}