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
    ListNode* middleNode(ListNode* head) {
    //     if(head == NULL || head->next == NULL)return head;

    //     ListNode* slow = head;
    //     ListNode* fast = head->next;

       

    //     while(fast->next != NULL and fast->next->next != NULL){
    //         slow = slow->next;
    //         fast = fast->next->next;
    //     }
    //     return slow->next;

    // }

    int n = 0;
    ListNode* root = head;
    while(head != NULL){
        head = head->next;
        n++;
    }
    head = root;
    int sz = n/2;
    for(int i=0; i<sz; i++){
        head = head->next;
    }

    return head;
    }
    
};