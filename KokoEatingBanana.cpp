class Solution {
public:
    bool could_eat(vector<int>&piles,int h,int speed)
    {
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]%speed==0)
            {
                h-=(piles[i]/speed);

            }
            else
            {
                h-=(piles[i]/speed)+1;
            }
            if(h<0)
            {
                return false;
            }
        }
        return true;

    }



    int minEatingSpeed(vector<int>&piles,int h) 
    {
        int left=1,right=INT_MIN;
        for(auto j:piles)

        {
            right=max(right,j);
        }


        while(left<=right)
        {
            int mid=(left+right)/2;
            if(could_eat(piles,h,mid))
            {
                right=mid-1;
            }
            else
            {
                left=mid+1;
            }
        }
        return left;
    }
};


// class Solution {
// public:
//     int minEatingSpeed(vector<int>& piles, int h) {

//         int n = piles.size();
//     int ans =0;
//         int minvalk = 0;
//         int maxval =piles[0];

//         for(int i =0; i < n ; i++){
//             minvalk += piles[i];

//             if(piles[i] > maxval){
//                 maxval = piles[i];
//             }

//         }

//         minvalk =minvalk/h;
    
//     for(int k = minvalk; k < maxval; k++){
//        int cnt =0; 
//         for(int i =0; i <n; i++){
//             if(piles[i] <= minvalk){
//                 cnt ++;
//             }

//             else{
//                 if(piles[i] % minvalk == 0){
//                     cnt += piles[i] / minvalk;
//                 }

//                 else{
//                     cnt += piles[i]/minvalk +1;
//                 }
//             }
//         }

//         if(cnt <= h){
          
//             break;
//         }
//     }

//         return minvalk;
//     }
// };
