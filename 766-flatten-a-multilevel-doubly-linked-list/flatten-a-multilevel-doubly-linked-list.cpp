/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;

        Node* curr = head;

        while(curr){
            if(curr->child){
                Node* nextnode = curr->next;
                Node* childnode = flatten(curr->child);

                curr->next = childnode;
                childnode->prev = curr;

                Node* tail = childnode;
                while(tail->next != NULL){
                    tail = tail->next;
                }

                if(nextnode){
                    tail->next = nextnode;
                    nextnode->prev = tail;
                }

                curr->child = NULL;
            }

            curr = curr->next;
        }

        return head;
    }
};