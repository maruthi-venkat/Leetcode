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
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* temp = NULL;
        ListNode* temp1 = head;
        ListNode* temp2 = head -> next;

        while(temp1){
            temp1 -> next = temp;
            temp = temp1;
            temp1 = temp2;
            if(temp2)
                temp2 = temp2 -> next;
        }

        return temp;
    }
};