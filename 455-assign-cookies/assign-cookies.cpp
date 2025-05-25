class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());  // sort greed factors
        sort(s.begin(), s.end());  // sort cookie sizes

        int child = 0, cookie = 0;
        int n = g.size(), m = s.size();

        while (child < n && cookie < m) {
            if (s[cookie] >= g[child]) {
                // Give cookie to child
                child++;
            }
            cookie++;
        }

        return child;
    }
};
