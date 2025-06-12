class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int len = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }else{
                    len = max(len,i-st.top());
                }
            }
        }

        return len;
    }

    /////////////notes//////////////

    /*
    \U0001f4a1 Step 1: Pehle Samajh — Problem Kya Puchh Raha Hai?
"Longest valid (well-formed) substring of parentheses."

Soch:

Valid matlab har '(' ka matching ')' ho.

Continuous substring chahiye (not just count).

\U0001f9f1 Step 2: Brute Force se Sochne Ki Koshish Kar
Pehle tu manually paper pe try kar:

text
Copy
Edit
s = ")()())"
        ↑
        yaha se ek substring end hoti hai
Ab khud se questions puchh:

Is position se valid substring ban rahi hai kya?

Uska length kaise pata chale?

Yahan tu realize karega ki:

Tumhe track rakhna padega kaha se valid shuru ho rahi hai.

Aur tumhe kab reset karna hai jab koi unmatched bracket mil jaaye.

\U0001f3af Step 3: Jab Stack Use Karega, Samajh Yeh Kyun Kaam Karta Hai
'(' mila → store karo (kyunki iska match abhi baad mein aayega)

')' mila:

Agar koi '(' hai stack mein → match ban gaya → pop

Nahi hai → galat closing bracket → yahan se naye valid ke liye reset

Aur yahi logic tum stack mein index daal kar apply karte ho.

\U0001f9e0 Step 4: Yeh Condition Kab Sochi Jati Hai?
❗ “Stack empty ho gaya toh current index ko base bana lo”

Soch ke dekho — agar tumhare paas ')' aayi aur stack mein koi '(' nahi hai → iska matlab ab tak ka substring invalid tha.

Toh next valid substring yahin se start ho sakta hai → so yeh index tum stack mein base ke liye push karte ho.

\U0001f4c8 Step 5: Practice and Visualization
Yeh logic tabhi dimag mein aayega:

Jab tu manually 2–3 input test cases ko dry-run karega (line-by-line likh ke).

Ek baar tu khud index tracking karega (stack simulate karega) toh tera brain samjh jaayega ki:

Kya track karna hai?

Kyu current_index - st.top() se hi length milta hai?
*/
};