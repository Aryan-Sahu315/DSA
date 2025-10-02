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
    ListNode* deleteMiddle(ListNode* head) {
        if (head == NULL || head->next == NULL) {
               
            return NULL;
        }

    
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

    
        count = count / 2;

        
        temp = head;
        ListNode *prev = NULL;
        while (count > 0) {
            prev = temp;
            temp = temp->next;
            count--;
        }

        
        prev->next = temp->next;
        

        return head;
    }
};
