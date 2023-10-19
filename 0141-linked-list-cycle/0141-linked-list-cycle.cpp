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
    bool hasCycle(ListNode *head) {
        map<ListNode*,bool>visited;
        ListNode* temp = head;

        while(temp != NULL)
        {
            visited[temp] = true;
            temp = temp->next;
            if(visited[temp] == true)
            {
                return true;
            }
        }
        return false;
    }
};