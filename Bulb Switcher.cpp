class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

// class Solution {
// public:
//     int bulbSwitch(int n) {
        
//   vector<int> vec(n, 1);   

//   for(int i =0; i < n/2; i++){
//       vec[2*i + 1] = 0;
//   }
        
//    for(int i =0; i <n/3; i++){
//        if(vec[3*i +2] == 1){
//            vec[3*i + 2] =0;
//        }

//        else{
//             vec[3*i + 2] = 1;
//        }
//    }   
// for(int j =0; j < n-1; j++){
//    for(int i =0; i < n/j; i++){
//         if(vec[j*i] == 1){
//            vec[j*i] =0;
//        }

//        else{
//             vec[j*i] = 1;
//        }
//    }  
// }


// if(vec[n-1] == 1){
//            vec[n-1] =0;
//        }

//        else{
//             vec[n-1] = 1;
//        }

// int cnt =0;

//     for(int i =0; i <n;i++)
//     {
//         if(vec[i] == 1){
//             cnt++;
//         }
//     } 

//     return cnt;


//    }
// };
