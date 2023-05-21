
#include <list>
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
    void swapSwap(ListNode* start, ListNode* mid){
        while(mid && start){
            ListNode* temp1 = start->next;
            ListNode* temp2 = mid->next;
            start->next = mid;
            mid->next = temp1;
            start = temp1;
            mid = temp2;
        }
    }

    void reorderList(ListNode* head) {
        // navigate to mid
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* current = slow->next;
        ListNode* previous = nullptr;
        while(current){
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }
        slow->next = previous;
        fast = slow->next;
        slow->next = nullptr;
        swapSwap(head, fast);
    }
};