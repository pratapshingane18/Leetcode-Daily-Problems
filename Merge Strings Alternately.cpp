class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string res = "";

        int n = word1.size();
        int m = word2.size();
        int i = 0, j = 0; // Counters for word1 and word2

        while (i < n || j < m) {
            if (i < n) {
                res += word1[i++]; // Append character from word1
            }

            if (j < m) {
                res += word2[j++]; // Append character from word2
            }
        }

        return res;
    }
};
