class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
   
    while(l<=r)
    {
         mid=(l+r)/2;
        
    
    if(nums[mid]==target)
        return mid;
    else if(nums[mid]<target)
        l=mid+1;
    else
        r=mid-1;
    }
    int l1=0;
    if(nums[mid]<target)
    l1=mid+1;
    else
    l1=mid;
    return l1;
        
    }
};
