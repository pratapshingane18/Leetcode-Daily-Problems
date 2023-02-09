class Solution {
public:
    long long distinctNames(vector<string>& ideas) {

        long long disName = 0;
        vector<unordered_set<string>> arr(26);
        for (string s : ideas) 
            arr[s[0] - 'a'].insert(s.substr(1));
        
        for (int i = 0; i < 25; i++) {
            for (int j = i + 1; j < 26; j++) {
                unordered_set<string> set;
                set.insert(arr[i].begin(), arr[i].end());
                set.insert(arr[j].begin(), arr[j].end());
                disName += (arr[i].size() - set.size()) * (arr[j].size() - set.size());
            }
        }
        return disName * 2;
 


//     unordered_set<string> names;
//    for (int i = 0; i < ideas.size(); i++) {
//         for (int j = i + 1; j < ideas.size(); j++) {
//             string ideaA = ideas[i];
//             string ideaB = ideas[j];
//             swap(ideaA[0], ideaB[0]);
//             if (find(ideas.begin(), ideas.end(), ideaA) == ideas.end() &&
//                 find(ideas.begin(), ideas.end(), ideaB) == ideas.end()) {
//                 names.insert(ideaA + " " + ideaB);
//             }
//         }
//     }

//     return 2*names.size();
        
    }
};
