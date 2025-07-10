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
    ListNode* reverse(ListNode* temp){
        if(temp == NULL){
            return NULL;
        }
        ListNode* root = temp;
        ListNode* prev = NULL;

        while(root != NULL){
            ListNode* nextnode = root->next;
            root->next = prev;
            prev = root;
            root = nextnode;
        }

        return prev;
    }

    ListNode* helper1(ListNode* root, int k){
        k = k-1;

        while(root != NULL and k>0){
            k--;

            root = root->next;
        }
        return root;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;

        ListNode* prev = NULL;

       while(temp != NULL){
        ListNode* kthnode = helper1(temp,k);
        if(kthnode == NULL){
            if(prev){
                prev->next = temp;
            }

            break;
        }
        ListNode* nextnode = kthnode->next;
        kthnode->next = NULL;

        ListNode* rev = reverse(temp);

        if(temp == head){
            head = kthnode;
        }else{
            prev->next = rev;//hum prev me previous part ka last node store kr re
        }

        prev = temp;
        temp = nextnode;
       }

       return head;

    }
};