class Solution {
public:
    int maxProfit(vector<int>& prices) {

 
        int n = prices.size();
        int maximumProfit = 0, minStockVal = INT_MAX;
        int i = 0;
        while (i < n) {
            minStockVal = min(minStockVal, prices[i]);
           
            if (prices[i] >= minStockVal)
                maximumProfit = max(maximumProfit, prices[i] - minStockVal);
            i++;
        }
        return maximumProfit;
    

//         int currmin = prices[0];
    
//         int minindex =0;
        

//         for(int i =0; i < prices.size() ; i++){
//             if(prices[i] < currmin){
//                 currmin = prices[i];
//                 minindex = i;
//             }
//         }
// int currmax = prices[minindex];


//         if(minindex == prices.size() -1){
//             return 0;
//         }

//         else{
            
         
//           for(int i =minindex ; i < prices.size()  ; i++){
//             if(prices[i] > currmin){
//                 currmax = prices[i];
              
//             }
//         }



//         }
// return currmax;
//         // if(currmax > currmin){
//         //     return currmax - currmin;
//         // }

//         // else{
//         //     return 0;
//         // }


        
    }
};
