
class Solution {
public:
    int isVowel(char c){
        if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') return 1;
        return 0;
    }
    int maxVowels(string s, int k) {
        int max=0;
        int c=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])==1) c++;
        }
        cout<<c<<endl;
        int i=0;
        max=c;
        int j=k;
        while(j<s.size()){
            c=c+isVowel(s[j++])-isVowel(s[i++]);
            cout<<c<<endl;
            if(c==k) return k;
            if(c>max) max=c;
        }
        return max;
    }
};
