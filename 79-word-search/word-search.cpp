class Solution {
public:
    bool helper(vector<vector<char>>&board,string word,int row,int col,int index,int n,int m){
        if(index == word.length()){
            return true;
        }

        if(row < 0 || col < 0 || row >= n || col >= m || board[row][col] == '!' || board[row][col] != word[index]){
            return false;
        }//board[row][col] != word[index] ye check krne ke liye h ki agar wo char boards ka index ke equal nhi milta kisi v direction me 

        char c = board[row][col];
        board[row][col] = '!';

        //top
        bool top = helper(board,word,row-1,col,index+1,n,m);
        //right
        bool right = helper(board,word,row,col+1,index+1,n,m);
        //bottom
        bool bottom = helper(board,word,row+1,col,index+1,n,m);
        //left
        bool left = helper(board,word,row,col-1,index+1,n,m);

        board[row][col] = c;//kahi v iss path me word nhi bnta kisi wajah se toh jo character ko humne ! kra tha usko wapas c krdenge taaki niche wale fxn me hum agar dusra path decide kre toh ye char hum firse use kr ske.backtracking ka part hai ye.

        return top || right || bottom || left;


    }
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();
        int index = 0;

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(board[i][j] == word[index]){
                    if(helper(board,word,i,j,index,row,col)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};