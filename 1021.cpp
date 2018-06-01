#include <stdio.h>
#define DQSIZE 2000

int N, M, A;

class Deque {
public:
    int m_buf[DQSIZE];
    int m_front, m_back;
    int m_size;
    
    Deque() : m_front(0), m_back(DQSIZE - 1), m_size(0) {}
    void push_front(int x) {
        m_front = (m_front - 1 + DQSIZE) % DQSIZE;
        m_buf[m_front] = x; m_size++;
    }
    
    void push_back(int x) {
        m_back = (m_back + 1) % DQSIZE;
        m_buf[m_back] = x; m_size++;
    }
    
    int pop_front() {
        int ret = m_buf[m_front];
        m_front = (m_front + 1) % DQSIZE;
        m_size--;
        return ret;
    }
    
    int pop_back() {
        int ret = m_buf[m_back];
        m_back = (m_back - 1 + DQSIZE) % DQSIZE;
        m_size--;
        return ret;
    }
    
    int front() { return m_buf[m_front]; }
    int back() { return m_buf[m_back]; }
    bool empty() { return m_size == 0; }
    int find(int x) {
        for(int i = 0; i < m_size; ++i) {
            if(m_buf[(m_front + i) % DQSIZE] == x) {
                return i;
            }
        }
        return -1;
    }
};

Deque dq;

int main() {
    int X;
    scanf("%d%d", &N, &M);
    
    for(int i = 1; i <= N; ++i) dq.push_back(i);
    
    int count = 0;
    while(M--) {
        scanf("%d", &X);
        while(dq.front() != X) {
            int idx = dq.find(X);
            if(idx <= dq.m_size / 2) {
                while(dq.front() != X) {
                    dq.push_back(dq.pop_front());
                    count++;
                }
            }
            else {
                while(dq.front() != X) {
                    dq.push_front(dq.pop_back());
                    count++;
                }
            }
        }
        dq.pop_front();
    }
    
    printf("%d\n", count);
    
    return 0;
}
