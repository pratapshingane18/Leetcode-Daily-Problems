// class Solution {
// public:
//     vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
//         int n1 = nums1.size();
//         int n2 = nums2.size();
//         vector<int> v1;
//         vector<int> v2;
//         vector<vector<int>> res;


//         for(int i =0; i < n1; i++){
//             for(int j =0; j < n2; j++){
//               if(nums1[i] == nums2[j]){
               
//                 break;
//             }
            
               
            
//             }
           
//         }

//           for(int i =0; i < n2; i++){
//             for(int j =0; j < n1; j++){
//             if(nums2[i] == nums1[j]){
               
//                 break;
//             }
//             else{
//                  v2.push_back(nums2[i]);
//             }
//             }
//         }

//         res.push_back(v1);
//         res.push_back(v2);

//         return res;
        
//     }
// };

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set1(nums1.begin(), nums1.end());
        unordered_set<int> set2(nums2.begin(), nums2.end());
        
        vector<int> distinct_nums1, distinct_nums2;
        for (int num : set1) {
            if (set2.count(num) == 0) {
                distinct_nums1.push_back(num);
            }
        }

        for (int num : set2) {
            if (set1.count(num) == 0) {
                distinct_nums2.push_back(num);
            }
        }

        return {distinct_nums1, distinct_nums2};
    }
};
