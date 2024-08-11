/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool flag = 0;
    ListNode *detectCycle(ListNode *head) {
        if(!head) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 0;
        while(slow){
            slow = slow -> next;
            count++;
            if(fast && fast -> next){
                fast = fast -> next -> next;
            }
            else{
                break;
            }

            if(slow == fast){
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            return nullptr;
        }

        slow = head;
        while(slow != fast){
            slow = slow -> next;
            fast = fast -> next;
        }

        return slow;
    }
};