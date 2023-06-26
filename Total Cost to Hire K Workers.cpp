class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>>pq; 
      
        int n=costs.size();
        int s=0,e=n-1; 
        for(int i=0;(i<candidates)&&s<=e;i++){ 
            pq.push({costs[s],s,1});
            s++;
            if(s<=e){ 
                pq.push({costs[e],e,-1});
                e--;
            }
            
        }
        long long ans=0;
        while(k--&&pq.size()){   
            vector<int>ele=pq.top(); 
            pq.pop();
            ans+=ele[0]; 
            if(s<=e){   
                if(ele[2]==1){
                    pq.push({costs[s],s,1});
                    s++;
                }
                else{
                    pq.push({costs[e],e,-1});
                    e--;
                }
            }
        }
        return ans;
    }
};
