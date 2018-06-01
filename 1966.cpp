#include <stdio.h>

#define QSIZE 200

int T, N, M;

class Queue {
public:
    int queue[QSIZE];
    int qf, qr;
    int size;
    
    void reset() {
        qf = 0;
        qr = -1;
        size = 0;
    }
    void enq(int x) {
        qr = (qr + 1) % QSIZE;
        queue[qr] = x;
        size++;
    }
    int deq() {
        int ret = queue[qf];
        qf = (qf + 1) % QSIZE;
        size--;
        return ret;
    }
};

Queue wq;
Queue iq;

int main() {
    int W;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &N, &M);
        
        wq.reset();
        iq.reset();
        
        for(int i = 0; i < N; ++i) {
            scanf("%d", &W);
            
            iq.enq(i);
            wq.enq(W);
        }
        
        int step = 1;
        while(wq.size) {
            int w = wq.deq();
            int i = iq.deq();
            
            bool found = false;
            for(int j = 0; j < wq.size; ++j) {
                if(wq.queue[(wq.qf + j) % QSIZE] > w) {
                    found = true;
                    break;
                }
            }
            if(found) {
                wq.enq(w);
                iq.enq(i);
            }
            else {
                if(i == M) {
                    printf("%d\n", step);
                    break;
                }
                step++;
            }
        }
    }
    
    return 0;
}
