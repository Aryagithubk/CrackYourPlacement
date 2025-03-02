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
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        ListNode* root = head;
        int count = 0;

        while(head != NULL){
            count++;
            head = head->next;
        }

        k = k%count;
        if(k == 0){
            return root;
        }
        int pos = (count-k);

        head = root;

        for(int i=1; i<pos; i++){
            head = head->next;
        }


        ListNode* temp = head->next;
        head->next = NULL;
        ListNode* start = temp;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = root;
        return start;

    }
};