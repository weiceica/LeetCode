using namespace std;
struct ListNode {
   int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ln = new ListNode();
        ListNode* head = ln;
        while(l1 || l2){
            int val;
            if(!l1){
                val = carry + l2->val;
                l2 = l2->next;
            }
            else if(!l2){
                val = carry + l1->val;
                l1 = l1->next;
            }
            else{
                val = carry + l1->val + l2->val;
                l2 = l2->next;
                l1 = l1->next;
            }
            head->next = new ListNode(val % 10);
            head = head->next;
            val >= 10 ? carry = 1 : carry = 0;
        }
        if(carry == 1) head->next = new ListNode(1);
        return ln->next;
    }
};