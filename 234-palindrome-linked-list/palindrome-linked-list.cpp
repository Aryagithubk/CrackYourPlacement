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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }

        // ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* newnode = slow;
        ListNode* prev = NULL;
        ListNode* next = newnode->next;

        while(newnode != NULL){
            newnode->next = prev;
            prev = newnode;
            newnode = next;

            if(newnode != NULL){
                next = newnode->next;
            }
        }
        // ListNode* val1 = prev;
        while(prev != NULL){
            if(head->val != prev->val){
                return false;
            }

            head = head->next;
            prev = prev->next;
        }

        return true;
    }
};