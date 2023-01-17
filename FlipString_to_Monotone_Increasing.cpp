class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int n = s.length();
    int Zerocnt =0;
    int onecnt =0;
    int ans =0;
        for(int i=0; i < n; i++){
            if( s[i] == '0'){
                Zerocnt++;

            }
        }
        ans =Zerocnt;
         for(int i=0; i < n; i++){
            if( s[i] == '1'){
                onecnt++;

            }

            else{
                Zerocnt--;
            }

            ans = min(ans, onecnt + Zerocnt);
        }


        return ans;
        
    }
};
