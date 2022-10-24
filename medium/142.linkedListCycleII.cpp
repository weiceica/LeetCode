
using namespace std;
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(nullptr) {}
  };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != nullptr && fast != nullptr){
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr) return nullptr;
            fast = fast->next;
            if(slow == fast) break;
        }
        if(fast == nullptr) return nullptr;
        while(head != fast){
            
            head = head->next;
            fast = fast->next;
        }
        return fast;
    }
};