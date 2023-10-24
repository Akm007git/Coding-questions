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
        while(head != NULL){
            head = head->next;
            cnt++;
        }
        return cnt;
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
         if(head == NULL){
            return NULL;
        }

        if(head -> next == NULL){
            return NULL;
        }

         ListNode * s = head, *f = head, *prev = NULL;

        while(f!= NULL && f->next != NULL){
            prev = s;
            f = f->next -> next;
            s = s -> next; 
        }

        prev->next =  s->next;
            return head;
    }
};