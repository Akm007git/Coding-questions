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
    int length(ListNode* head){
        int cnt = 0 ;
        while(head!=NULL){
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int k) {

        if(head->next == NULL){
            return NULL;
        }

        // kth node from end = n-k+1 th node from front
        int n = length(head);
        int i = 1, pos = n - k + 1;

        // when pos = 1 ->means delete head node ex - [1,2] , n = 2 
        if(pos == 1){
            head = head->next;
            return head;
        }

        ListNode*prev = NULL, *curr = head;

        while(i< pos){
            prev = curr;
            curr = curr->next;
            i++;
        }
        
        prev->next = curr->next;
        return head;
    }
};