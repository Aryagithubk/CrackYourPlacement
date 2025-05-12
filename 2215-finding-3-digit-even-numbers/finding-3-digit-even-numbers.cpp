class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int>st;
        int n = digits.size();
        vector<int>res;

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || j==k || k==i){
                        continue;
                    }
                    int a = digits[i];
                    int b = digits[j];
                    int c = digits[k];

                    if(a != 0 and c%2 == 0){
                    int num = 100 * a + 10* b + c;
                    st.insert(num);
                }
            }
        }
    }

    return vector<int>(st.begin(),st.end());
    }
};