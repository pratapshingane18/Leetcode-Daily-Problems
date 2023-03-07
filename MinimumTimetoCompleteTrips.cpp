class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        sort(time.begin(), time.end());

        long long minn =0, maxx = pow(10,14), ans = maxx;
       int n = time.size();

        while(minn < maxx ){
            long long mid = (minn+maxx)/2;

            long long cnt = 0;

        for(int i =0; i < n; i++){
               cnt += (mid / time[i]);
            }

        if(cnt >= totalTrips){
            ans = min(ans,mid),maxx=mid;

        }

        else{
            minn = mid +1;
        }
        }

        return ans;

//         long long max =0;
//         vector<float> v;

//     int n = time.size();
//     int currmax = time[0];

//     for(int i =1; i < n; i++){
//         if(time[i] > currmax){
//             currmax =time[i];
//         }
//     }

//     for(int i =0; i < n; i++){
//         v.push_back(currmax / time[i]);
//     }
// int sum =0;
//     for(int i =0; i < v.size(); i++){
//         sum += v[i];
//     }
//  long long id =1;
// while(totalTrips > sum){

   
//     sum = sum*id;

//     id++;

// }
// if(n==1){
//     return time[0];
// }
// return id*n;

        
    }
};
