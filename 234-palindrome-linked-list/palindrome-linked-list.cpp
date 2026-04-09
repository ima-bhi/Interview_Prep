/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head; 
        //LL = 1->2->2->1;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        // slow = 2, fast = 1
        ListNode* prev = nullptr;
        
        while (slow) {
            ListNode* temp = slow->next; // temp =2
            slow->next = prev; 
            prev = slow;  // prev=2
            slow = temp;  // temp 2
        }
        /*
        LL -> 1-> 2-> 1-> 2 ;
        prev -> reverse the LL from mid to end 
         */
        ListNode* first = head;   // first = 1
        ListNode* second = prev;  // prev = 1

        // checking the val equal or not
        while (second) {
            if (first->val != second->val) {
                return false;
            }
            first = first->next;
            second = second->next;
        }

        return true;
    }
};