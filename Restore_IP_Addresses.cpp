class Solution {
public:

    vector<string> restoreIpAddresses(string s) {

        vector<string> res;
        vector<string> temp;

        getIPs(temp, res, s , 0);
        return res;

            
        
    }

     void getIPs(vector<string> & temp, vector<string> & res, string &s, int index){

        if(index == s.length() && temp.size() == 4 ){
            string valid = temp[0] + '.' + temp[1] + '.' + temp[2] + '.' + temp[3];
            res.push_back(valid);
            return;

        }

        string Tempstr = "";
        for(int i =index; i < s.length() && temp.size() < 4; i++){
            if(s[i] - '0' > 9) {
                continue;
            }

            Tempstr += s[i];
            int tempInt = stoi(Tempstr);
            if(0 <= tempInt && tempInt <= 255){
                temp.push_back(Tempstr);
                getIPs(temp, res,s,i+1);
                temp.pop_back();
            }

            if(tempInt <= 0 || tempInt > 255){
            break;
        }


        }

        
    }

};
