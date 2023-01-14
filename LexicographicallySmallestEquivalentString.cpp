


class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char arr[26];

        for(int i =0; i < 26; i++){
            arr[i] = 'a' +i;
        }
        
        int n = s1.size();
        for(int i =0; i < n; i++){
            char replace = max(arr[s1[i] - 'a'], arr[s2[i] - 'a']);
            char replaceWith = min(arr[s1[i] - 'a'], arr[s2[i] - 'a']);

            for(int j = 0; j <  26; j++){
                if(arr[j] == replace){
                    arr[j] = replaceWith;
                }
            }
        }
        for(int i =0; i <baseStr.size();i++){
            baseStr[i] = arr[baseStr[i] - 'a'];
        }

        return baseStr;

    }
};
