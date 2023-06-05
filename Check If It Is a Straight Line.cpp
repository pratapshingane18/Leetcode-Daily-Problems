class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x;
        int x1 = coordinates[0][0];
        int x2 = coordinates[1][0];
        int y1 = coordinates[0][1];
        int y2 = coordinates[1][1];


        for(int i =2; i < coordinates.size(); i++){
            // if(((y2-y1)/(y1 - coordinates[i][1])) != ((x2 - x1)/(x1-coordinates[i][0]))){
            //     return false;
            // }

             if(((y2-y1)*(x1-coordinates[i][0])) != ((x2 - x1)*(y1 - coordinates[i][1]))){
                return false;
            }
        }

        return true;
    }
};
