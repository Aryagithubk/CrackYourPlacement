class Solution {
public:
    string robotWithString(string s) {
        vector<int> freq(26, 0);  // frequency of remaining characters in s

    for (char ch : s) {
        freq[ch - 'a']++;
    }

    stack<char> t;            // robot's current string t
    string result = "";       // final output string
    char minChar = 'a';       // current minimum char remaining in s

    for (char ch : s) {
        t.push(ch);
        freq[ch - 'a']--;

        // update minChar to the smallest character still remaining in s
        while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
            minChar++;
        }

        // keep popping from t if top is <= minChar
        while (!t.empty() && t.top() <= minChar) {
            result += t.top();
            t.pop();
        }
    }

    // add remaining elements from t
    while (!t.empty()) {
        result += t.top();
        t.pop();
    }

    return result;
    }
};