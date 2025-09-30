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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode *temp=head;
        ListNode *prev=NULL;
        while(temp!=NULL)
        {
            count =count+1;
            temp=temp->next;
        }
        temp=head;
        count =count-n;
        if(count==0)
        {
            ListNode *temp2=head;
            head=temp2->next;
            delete temp2;

        }
        else
        {
            while(count)
            {
                
                prev=temp;
                temp=temp->next;
                count--;
            }
            prev->next=temp->next;
            delete temp;
        }
        return head;


        
    }
};