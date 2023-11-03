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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        int carry = 0; // WE HAVE TO HANDLE THE CARRY

        while(l1 != NULL || l2 != NULL || carry != 0)
        {
            int sum = 0;
            if(l1 != NULL)
            {
                sum += l1->val;
                l1=l1->next;
            }

            if(l2 != NULL)
            {
                sum += l2->val;
                l2=l2->next;
            }

            sum += carry; // ULTIMATE LUY SUM = L1+L2 + CARRY FOR EACH TIME
           
            carry = sum /10;  // update the carry for next step;
            ListNode* node = new ListNode(sum%10); // this is the value of sum of each iteation
            temp->next = node; // create new list using sum

            // updation 
            temp = temp->next;
        }

        return dummyNode->next;
    }
};