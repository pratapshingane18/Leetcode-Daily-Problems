class Solution {
public:


    int strStr(string haystack, string needle) {

     int M = haystack.length();
    int N = needle.length();

    for (int i = 0; i <= M - N +1; i++) {
       if(haystack.substr(i,N) == needle){
           return i;
       }
        
    }

    return -1;

        
    }
};
