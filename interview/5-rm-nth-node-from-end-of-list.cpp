
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // basecase
        if(head->next == nullptr) return nullptr;

        int fcount = 1;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr){
            fast = fast->next;
            fcount++; 
        }
        if(fcount == n){
            head = head->next; 
            return head;     
        }
        int scount = fcount - n;
        for(int i = 1; i < scount; ++i){
            slow = slow->next;
        }
        ListNode* temp = slow;
        temp = temp->next;
        slow->next = temp->next;
        return head;
    }
};