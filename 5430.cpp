#include <stdio.h>
#define DQSIZE 200000

int T, n;
char inst[100001];
char array_string[500000];

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

void divide() {
    char *p = &array_string[1];
    int idx = 0;
    int num = 0;
    if(*p == ']') return;
    
    int count = 0;
    while(*p) {
        if(*p >= '0' && *p <= '9') {
            num = num * 10 + (*p - '0');
        }
        else {
            dq.push_back(num);
            count++;
            num = 0;
            if(*p == ']' || count == n) break;
        }
        p++;
    }
}

int main() {
    int a;
    scanf("%d", &T);
    while(T--) {
        scanf("%s", inst);
        scanf("%d", &n);
        scanf("%s", array_string);
        divide();
        
        char *p = inst;
        int mode = 0; // 0 : front, 1 : back
        int error = 0;
        while(*p) {
            switch(*p) {
                case 'R':
                mode = 1 - mode;
                break;
                case 'D':
                if(dq.empty()) {
                    error = 1;
                    break;
                }
                if(!mode) {
                    dq.pop_front();
                }
                else {
                    dq.pop_back();
                }
                break;
            }
            p++;
        }
        
        if(!error) {
            printf("[");
            if(!mode) {
                while(dq.m_size) {
                    printf("%d", dq.pop_front());
                    if(dq.m_size > 0) printf(",");
                }
            }
            else {
                while(dq.m_size) {
                    printf("%d", dq.pop_back());
                    if(dq.m_size > 0) printf(",");
                }
            }
            printf("]\n");
        }
        else {
            printf("error\n");
        }
    }
    
    return 0;
}
