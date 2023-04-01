class Solution {
public:


int binSearch(vector<int>& nums,int first, int last, int target){
 
    if(first > last){
         return -1;
    }

    int mid = (first + last)/2;

    if(nums[mid] == target){
        return mid;
    }

    if(target > nums[mid] ){
        return  binSearch(nums,mid+1,last,target);
    }

    else{
        return binSearch(nums,first,mid -1,target);
    }

  
}


    int search(vector<int>& nums, int target) {
        int first = 0;
        int last = nums.size()-1;
       return binSearch(nums,first,last,target);

    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//        int s=0,e=nums.size()-1;
//        while(s<=e){
//            int m=(s+e)/2;
//            if(nums[m]==target)return m;
//            else if(nums[m]>target)e=m-1;
//            else s=m+1;
//        }
//        return -1; 
//     }
    
// };
