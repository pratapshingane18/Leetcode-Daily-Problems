class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int currmax = gain[0];
        int max = gain[0];

        for(int i =1 ; i< gain.size(); i++){
            currmax += gain[i];

            if(currmax > max){
                max = currmax;
            }
        }

        if(max < 0){
            return 0;
        }
        else
        return max;
        
    }
};
