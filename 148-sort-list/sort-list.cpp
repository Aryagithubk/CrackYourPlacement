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
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode* root = head;

        if(head == NULL || head->next == NULL){
            return head;
        }

        while(head != NULL){
            arr.push_back(head->val);
            head = head->next;
        }

        sort(arr.begin(),arr.end());
        head = root;

        for(int i=0; i<arr.size(); i++){
            head->val = arr[i];
            head = head->next;
        }

        head = root;
        return head;
    }
};