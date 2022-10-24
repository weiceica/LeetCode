

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* s1 = head;
        int count = 0;
        while(s1!= nullptr){
            s1=s1->next;
            count++;
        }
        for(int i = 0; i < count/2; i++){
            head = head->next;
        }
        return head;
    }
};