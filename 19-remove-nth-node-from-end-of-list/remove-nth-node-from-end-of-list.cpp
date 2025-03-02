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
        if(head == NULL || head->next == NULL){
            return NULL;
        }

        int count = 0;
        ListNode* temp = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        if(n == count){
           return head->next;
        }

        temp = head;

        int pos = count-n;

        for(int i=1; i<=pos-1; i++ ){
            temp = temp->next;
        }

        if(temp->next != NULL){
            temp->next = temp->next->next;
        }

        return head;

    }
};