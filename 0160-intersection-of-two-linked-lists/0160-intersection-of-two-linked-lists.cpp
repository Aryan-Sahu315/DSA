class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int count1 = 0, count2 = 0;
        ListNode *temp1 = headA, *temp2 = headB;

        // Count lengths
        while (temp1 != NULL) {
            count1++;
            temp1 = temp1->next;
        }
        while (temp2 != NULL) {
            count2++;
            temp2 = temp2->next;
        }

        // Reset pointers
        temp1 = headA;
        temp2 = headB;

        // Align the pointers
        while (count1 > count2) {
            temp1 = temp1->next;
            count1--;
        }
        while (count2 > count1) {
            temp2 = temp2->next;
            count2--;
        }

        // Traverse together until intersection
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1 == temp2) {
                return temp1;  // Intersection point
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        return NULL;  // No intersection
    }
};
