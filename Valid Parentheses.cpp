class Solution {
public:
    bool isValid(string s) {
        stack<char> st;  
        for(auto i:s)  
        {
            if(i=='(' or i=='{' or i=='[') st.push(i); 
            else
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}') or (st.top()=='[' and i!=']')) return false;
                st.pop();
            }
        }
        return st.empty();  
    }
};





// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> stk;

//         for (int i=0; i<s.length(); i++){
//         if (s[i] == '(' || s[i] == '{' || s[i] == '['){
//             stk.push(s[i]);
//         } else if (s[i] == ')' || s[i] == '}' || s[i] == ']'){
//             if (stk.empty()){
//                 return false;
//             } else {
//                 stk.pop();
//             }
//         }
//     }
//     return stk.empty() ? true : false;



        
//     }
// };
