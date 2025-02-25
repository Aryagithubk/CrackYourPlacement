class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) : val(x),next(NULL){}
    };

    Node* head;
    int size;

    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    int get(int index) {
        if(index >= size || index < 0){
            return -1;
        }
        Node* current = head;
        for(int i=0; i<index; i++){
            current = current->next;
        }

        return current->val;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node(val);
        newnode->next = head;
        head = newnode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newnode = new Node(val);

        if(head == NULL){
            head = newnode;
        }else{

        Node* curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = newnode;
        }
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > size || index < 0){
            return;
        }
        if(index == 0){
            addAtHead(val);
            return;
        }
        Node* newnode = new Node(val);
        Node* curr = head;

        for(int i=0; i<index-1; i++){
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= size || index < 0){
            return;
        }

        if(index == 0){
            Node* temp = head;
            head = head->next;
            delete temp;
        }else{
        Node* curr = head;
        for(int i=0; i<index-1; i++){
            curr = curr->next;
        }
        Node* todelete = curr->next;
        curr->next = curr->next->next;
        delete todelete;
    }
    size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */