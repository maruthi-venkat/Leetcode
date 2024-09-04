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
        if(!head || !head -> next) return head;

        ListNode* slow = head;
        ListNode* fast = head -> next;

        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        
        ListNode* temp1 = slow -> next;
        slow -> next = NULL;
        ListNode* temp = nullptr;
        ListNode* temp2 = temp1 -> next;
        while(temp1){
            temp1 -> next = temp;
            temp = temp1;
            temp1 = temp2;
            if(temp2) temp2 = temp2 -> next;
        }

        
        temp1 = head;
        while(temp){
            if(temp -> val != temp1 -> val){
                return false;
            }
            temp = temp -> next;
            temp1 = temp1 -> next;
        }

        return true;
    }
};