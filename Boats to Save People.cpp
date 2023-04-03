class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int first = 0;
        int last = people.size() - 1;
        int cnt = 0;

        sort(people.begin(), people.end());

      while(first <= last){
            if(people[first] + people[last] <= limit ){
                cnt ++;
                first++;
                last--;

            }

            else{
                cnt++;
                last--;
            }
        }

        return cnt;
    }
};
