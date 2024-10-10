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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode* root = head;
        int l = 0;

        while(head != NULL){
            head = head->next;
            l++;
        }

        head = root;
        k = k%l;
        int sz = l-k;

        for(int i=0; i<k; i++){
            ListNode* temp = head;

            while(temp->next->next != NULL){
                temp = temp->next;
            }
            ListNode* end = temp->next;
            temp->next = NULL;
            end->next = head;
            head = end;
        }

        return head;
    }
};