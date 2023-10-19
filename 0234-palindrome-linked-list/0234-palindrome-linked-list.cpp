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
ListNode* findMid(ListNode* &head)
{
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next; 
    }
    return slow;
   
}

ListNode* getreverse(ListNode* head)
{
    
        ListNode* current = head;
        ListNode* previous = NULL;

        while(current != NULL)
        {
            ListNode* forward = current->next;
            current->next = previous;

            // updation
            previous = current;
            current = forward;
        }
        return previous;
    
}

public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL)
        {
            return false;
        }
        
        if(!head->next)
        {
            return true;
        }

        ListNode* midHead = findMid(head);
        ListNode* temp = midHead->next;
        ListNode* reverseHead = getreverse(temp);

        ListNode* head1 = head;
        ListNode* head2 = reverseHead;

        while(head2)
        {
            if(head1->val == head2->val)
            {
                head1 = head1->next;
                head2 = head2->next;
            }
            else
            {
                return false;
            }
        }
        return true;
        
        
    }
};