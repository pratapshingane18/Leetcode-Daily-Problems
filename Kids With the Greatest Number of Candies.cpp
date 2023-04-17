class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> res;

        int max =0;

// finding max element
        for(int i =0; i < candies.size(); i++){
            if(candies[i] > max){
                max = candies[i];
            }
        }
// find the number or limit above which is extraCandies are added then condition will be fulfilled
        max = max - extraCandies;

// Checking for each index and adding result to res vector
        for(int i =0; i < candies.size(); i++){
            if(candies[i]  >= max){
                res.push_back(true);
            }
            else{
                res.push_back(false);
            }
        }

        // returning res vector
        return res;
    }
};
