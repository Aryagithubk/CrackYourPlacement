class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;

        q.push({beginWord,1});
        unordered_set<string> st(wordList.begin(),wordList.end());//using unordered for faster as it gives O(1) for search and deletion
    st.erase(beginWord);
    while(!q.empty()){
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == endWord){
            return steps;
        }

        for(int i=0; i<word.size(); i++){
            char ch = word[i];

            for(char j = 'a'; j<= 'z'; j++){
                word[i] = j;

                if(st.find(word) != st.end()){
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }

            word[i] = ch;//resetting with same character to word for next transformation
        }
    }

    return 0;
}
};