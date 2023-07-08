// Definition for a Node.
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr; 
        Node* newStartNode = new Node(node->val);
        unordered_map<Node*, Node*> umap;
        umap[node] = newStartNode;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curNode = q.front();
            q.pop();
            for(int i = 0; i < curNode->neighbors.size(); ++i){
                if(umap.find(curNode->neighbors[i]) == umap.end()){
                    umap[curNode->neighbors[i]] = new Node(curNode->neighbors[i] -> val);
                    q.push(curNode->neighbors[i]);
                }
                umap[curNode] -> neighbors.push_back(umap[curNode->neighbors[i]]);
            }
        }
        return newStartNode;
    }
};