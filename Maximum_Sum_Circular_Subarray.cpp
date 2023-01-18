class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
       // 5 pointer approach:

       int temp_Max =0;
        int temp_Min =0;

        int totalSum =0;

        int MinSubArrSum = INT_MAX;

        int MaxSubArrSum = INT_MIN;

        int n = nums.size();

        for(int i =0; i < n; i++){
            totalSum += nums[i]; // find Sum array

    //Finding MaxSumArray in straight Line

        temp_Max += nums[i];
        MaxSubArrSum = MaxSubArrSum < temp_Max ? temp_Max:MaxSubArrSum;
        temp_Max = temp_Max < 0? 0:temp_Max;
    // Finding MinSubArray in Straight Line
         temp_Min += nums[i];
        MinSubArrSum = MinSubArrSum > temp_Min ? temp_Min:MinSubArrSum;
        temp_Min = temp_Min > 0? 0:temp_Min;


        }

        // if all elements are Negative
         if(totalSum == MinSubArrSum){
            return MaxSubArrSum;
        }
        // if all elements are not negative
        return max(MaxSubArrSum,(totalSum - MinSubArrSum));
    }
};
