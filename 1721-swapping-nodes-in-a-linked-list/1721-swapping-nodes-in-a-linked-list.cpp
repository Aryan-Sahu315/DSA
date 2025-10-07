class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *temp = head;
        ListNode *last = head;
        int count = 0;

        // Step 1: Count total nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Move temp to k-th node
        temp = head;
        int t = k - 1;
        while (t > 0) {
            temp = temp->next;
            t--;
        }
        ListNode *first = temp;

        // Step 3: Move last to (count - k + 1)-th node
        int z = count - k;
        while (z > 0) {
            last = last->next;
            z--;
        }

        
        swap(first->val, last->val);

        return head;
    }
};
