class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        // Initialising a map for keeping count of distinct fruits
        map<int,int> fruit_count;

        // i is front pointer of sliding window
        // j is rear pointer of sliding window
        // ans will store the maximum subarray length
        int i=0,j=0,ans=0;
        while (i<fruits.size())
        {
            // picking up the fruit
            fruit_count[fruits[i]]++;
            // if no. of distinct fruits is more than two
            // we will move our rear pointer and unpick the fruits
            while (fruit_count.size()>2)
            {
                fruit_count[fruits[j]]--;
                // if fuit of a particular type are exhausted
                // clearing the index of that fruit
                if (fruit_count[fruits[j]]==0) {
                    fruit_count.erase(fruits[j]);
                }
                // moving rear pointer
                j++;
            }
            // Storing maximum subarray length with at most 2 distinct fruits
            ans=max(ans,i-j+1);
            // moving front pointer
            i++;
        }
        // returning the maximum subarray length
        return ans;
    }
};


// class Solution {
// public:


// void printFrequency(vector<int>& res,vector<int>& fruits)
// {
//     // Define an map
//     map<int, int> M;
 
//     // Traverse vector vec check if
//     // current element is present
//     // or not
//     for (int i = 0; i<fruits.size(); i++) {
 
//         // If the current element
//         // is not found then insert
//         // current element with
//         // frequency 1
//         if (M.find(fruits[i]) == M.end()) {
//             M[fruits[i]] = 1;
//         }
 
//         // Else update the frequency
//         else {
//             M[fruits[i]]++;
//         }
//     }
 
//     // Traverse the map to print the
//     // frequency
//     for (auto& it : M) {
//         res.push_back(it.second);
//     }
// }




   
//     int totalFruit(vector<int>& fruits) {
//         vector<int> res;
//         printFrequency(res,fruits);

//          sort(res.begin(), res.end(), greater<int>());

//          int n = res.size();
     
// if(n == 1){
//  return res[0];
// }    
//         else{
//             return res[0] + res[1];
//         }

//     }
// };
