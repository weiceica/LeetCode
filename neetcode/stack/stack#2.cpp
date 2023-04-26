#include <algorithm>
using namespace std;
class MinStack {
public:
    typedef struct node{
            int v;
            int curMin;
            node* next;
        }
        node;


    MinStack() : topN(nullptr){
        
    }
    
    void push(int val) {
        node* n = new node;
        n->v = n->curMin = val;
        n->next = nullptr;

        if(topN == nullptr){
            topN = n;
        }else{
            n->curMin = min(n->v, topN->curMin);
            n->next = topN;
            topN = n;
        }
    }
    
    void pop() {
        topN = topN->next;
    }
    
    int top() {
        return topN->v;
    }
    
    int getMin() {
        return topN->curMin;
    }
private:
    node* topN;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */