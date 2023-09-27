#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:       
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> umap;
        Node* firstHead = head;
        while(firstHead){
            umap[firstHead] = new Node(firstHead->val);
            firstHead = firstHead->next;
        }
        Node* secondHead = head;
        while(secondHead){
            umap[secondHead]->random = umap[secondHead->random];
            umap[secondHead]->next = umap[secondHead->next];
            secondHead = secondHead->next;
        }
        return umap[head];
    }
};