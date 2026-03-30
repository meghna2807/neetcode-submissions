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
        ListNode* dummy = head;
        int cnt = 0;
        while(dummy!=NULL){
            cnt++;
            dummy = dummy->next;
        }

        int k = cnt - n;
        if(k == 0) return head->next;
        
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(k > 0){
            prev = temp;
            temp = temp->next;
            k--;
        }
        prev->next = temp->next;

        return head;
    }
};
