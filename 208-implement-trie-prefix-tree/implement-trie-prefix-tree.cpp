class Node {
    public:

    map<char,Node*>children;
    bool end;

    void isEnd(){
       end = true;
    }

    Node(char ch){
        char val = ch;
        end = false;
        
    }

    Node(){
        end = false;
    }
};

class Trie {
public:
   Node* root;

    Trie() {
       root = new Node();
    }
    
    void insert(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++){
            char ch = word[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            }else{
                Node* child = new Node(ch);
                temp->children[ch] = child;
                temp = child;
            }
        }

        temp->isEnd();
    }
    
    bool search(string word) {
        Node* temp = root;

        for(int i=0; i<word.size(); i++){
            char ch = word[i];

            if(temp->children.count(ch) == 0){
                return false;
            }

            temp = temp->children[ch];
        }

        return temp->end;
    }
    
    bool startsWith(string prefix) {
        Node* temp = root;

        for(int i=0; i<prefix.size(); i++){
            char ch = prefix[i];

            if(temp->children.count(ch) == 0){
                return false;
            }

            temp = temp->children[ch];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */