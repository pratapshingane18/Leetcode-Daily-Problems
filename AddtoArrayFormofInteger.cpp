class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> res;
        int carry = k;
        for (int i = n-1; i >= 0; i--) {
            int sum = num[i] + carry;
            carry = sum / 10;
            res.push_back(sum % 10);
        }
        while (carry > 0) {
            res.push_back(carry % 10);
            carry /= 10;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};


// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& num, int k) {
//     int numb = 0;
//     vector<int> res;

//     int n = num.size();

//     for (int i = 0; i < n; i++) {
//     numb = numb * 10 + num[i];
// }

// numb = numb + k;

// while (numb > 0) {
//     int digit = numb % 10;
//     res.push_back(digit);
//     numb /= 10;
// }

// reverse(res.begin(), res.end());

// return res;
//     }
// };



// class Solution {
// public:
//     vector<int> addToArrayForm(vector<int>& num, int k) {
//         int carry=0;
//         vector<int> ans;
//         int i= num.size()-1;
//         while (k>0 || carry>0 || i>=0){
//             int v1=0;
//             if (i>=0)v1= num[i];
//             int val= v1+(k%10)+carry;
//             ans.push_back(val%10);
//             carry= val/10;
//             k/=10;
//             i--;
//         }
//         reverse(ans.begin(),ans.end());
//         return ans;
//     }
// };
