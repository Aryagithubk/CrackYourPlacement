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

    ListNode* reverseNode(ListNode* head){
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nextNode = curr->next;

        while(curr != NULL){
            curr->next = prev;
            prev = curr;
            curr = nextNode;

            if(curr != NULL){
                nextNode = curr->next;
            }
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode* root = head;
        ListNode* head1 = new ListNode();
        ListNode* root1 = head1;

        while(head != NULL){
            ListNode* temp = new ListNode(head->val);
            head1->next = temp;
            head1 = head1->next;
            head = head->next;
        }

        head1 = root1->next;
        head = root;
        ListNode* temp = reverseNode(head1);

        
        bool res = true;

        while(head != NULL){
            if(head->val != temp->val){
                return false;
            }
            head = head->next;
            temp = temp->next;
        }

        return res;

    

        

        

    }

};