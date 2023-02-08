
class Solution {
public:

    int jump(vector<int>& nums) {

    int jump=0;
    int curr =0;
    int far =0;

    for(int i =0; i < nums.size() -1; i++){
        far = max(far, nums[i] +i);

        if(i == curr){
            curr = far;
            jump++;
        }
    }

    return jump;
    }
};
