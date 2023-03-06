class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {

        int n = arr.size();
        vector<int> store;
        int num = 1;
        for(int i =0; i < n; i++){
            if(arr[i] != num){

                while(num != arr[i] ){
                store.push_back(num);
                num++;
                }

                if(num == arr[i]){
                    num++;
                }
            }

            else{
                num++;
            }

           
        }

        for(int i =1; i <=k; i++)
{
    store.push_back(arr[n-1]+i);
}       

return store[k-1];
    }
};
