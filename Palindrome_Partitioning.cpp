class Solution {
public:

void func(int index, string s, vector<string> &path, vector<vector<string>> &res){
    if(index == s.size()){
        res.push_back(path);
        return;
    }

    for(int i = index; i <s.size(); ++i){
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index, i - index +1));
            func(i+1, s, path,res);
            path.pop_back();
        }
    }
}

bool isPalindrome(string s, int start, int end){
    while(start <= end){
        if(s[start++] != s[end--]){
            return false;
        }
    }
    return true;
}

vector<vector<string>> partition(string s){
    vector<vector<string>> res;
    vector<string> path;
    func(0,s,path,res);
    return res;
}

// vector<vector<string>> res;

// void subString(string s, int n)
// {
//     // Pick starting point in outer loop
//     // and lengths of different strings for
//     // a given starting point
//     for (int i = 0; i < n; i++)
//         for (int len = 1; len <= n - i; len++)
//             res.push_back(s.sub(i, len));
// }


// // C++ Program to check whether the
// // Array is palindrome or not
 

 
// int palindrome(string s, int n)
// {
//     // Initialise flag to zero.
//     int flag = 0;
 
//     // Loop till array size n/2.
//     for (int i = 0; i <= n / 2 && n != 0; i++) {
 
//         // Check if first and last element are different
//         // Then set flag to 1.
//         if (s[i] != s[n - i - 1]) {
//             flag = 1;
//             break;
//         }
//     }
 
//     // If flag is set then print Not Palindrome
//     // else print Palindrome.
//     if (flag == 1)
//         return false;
//     else
//         return true;
// }



//     vector<vector<string>> partition(string s) {
//         n = s.size();
//         subString(s,n);

//         for(int i=0; i < res.size(); i++){
//             if(palindrome(s, n) == false){
//                 res[i].erase();
//             }
//         }


//         return res;
    
};
