class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int max_sat=0;
        int st=0; // to test all starting points
        while(st<satisfaction.size()){
            int temp=0;
            for(int i=st;i<satisfaction.size();++i){
                temp+=satisfaction[i]*(i-st+1);
            }
            max_sat=max(max_sat,temp);
            ++st;
        }
        return max_sat;
    }
};
