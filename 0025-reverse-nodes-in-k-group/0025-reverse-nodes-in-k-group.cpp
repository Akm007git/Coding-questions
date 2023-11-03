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
    private:
    int lengthOfLinklist(ListNode* &head)
    {
         int count = 0;
        ListNode* temp = head;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
         int length = lengthOfLinklist(head);
        if(length < k)
            return head;

        if(!head)
            return NULL;
        
        ListNode* previous = NULL;
        ListNode* current = head;
        ListNode* forward = NULL;
        int count  = 0;

        while(count < k && current != NULL)
        {
            forward = current->next;
            current->next = previous ;

            count++;
            previous = current;
            current = forward;
        }

        if(current != NULL)
        {
            head->next = reverseKGroup(forward,k);
        }

        return previous;

        
    }
};