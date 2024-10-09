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
        ListNode* root = head;
        int count = 0;

        while(head != NULL){
            head = head->next;
            count++;
        }

        head = root;
        int pos = count - n;

        if(count == n){
            return head->next;
        }

        for(int i=1; i<=pos-1; i++){
            head = head->next;
        }

        if(head->next != NULL){
            head->next = head->next->next;
        }

        head = root;
        return head;
    }
};