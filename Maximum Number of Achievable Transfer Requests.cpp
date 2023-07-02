class Solution {
public:
    void backtrack(int n,vector<vector<int>>& requests,vector<int>&employees,int &res,int index,int currReq){
     //base case
     if(index==requests.size()){
        
        for(int i=0;i<n;i++){
            if(employees[i]){
                return;
            }
        }

         res=max(res,currReq);
         return;
     }
      // Choose not to process the current request
      backtrack(n,requests,employees,res,index+1,currReq);

      //process the current request
      int from=requests[index][0];
      int to=requests[index][1];

      employees[from]--;//employess leaving 'from' building 
      employees[to]++;  //employees moving 'to' building

  
        backtrack(n,requests,employees,res,index+1,currReq+1);
  

      //backtrack
      employees[from]++;
      employees[to]--;
      
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        
        int maxiReq=0;

        vector<int>employees(n,0);

        backtrack(n,requests,employees,maxiReq,0,0);

        return maxiReq;
    }
};
