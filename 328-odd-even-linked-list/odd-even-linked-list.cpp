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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        // ListNode* even = new ListNode();
        ListNode* even = head->next;
        // ListNode* odd = new ListNode();
        ListNode* odd = head;
        ListNode* rooteven = even;


        // while(head != NULL){
        //     if(head->val % 2 == 0){
        //         ListNode* temp = new ListNode(head->val);
        //         even->next = temp;
        //         even = even->next;

        //     }else{
        //         ListNode* temp = new ListNode(head->val);
        //         odd->next = temp;
        //         odd = odd->next;
        //     }

        //     head = head->next;
        // }

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            odd = odd->next;
            even->next = even->next->next;
            even = even->next;
        }
        odd->next = rooteven;
        return head;

    }
};