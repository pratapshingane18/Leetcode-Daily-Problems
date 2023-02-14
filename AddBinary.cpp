class Solution {
public:

string addBinary(string a, string b) {

    string result;

    int i = a.size() -1;
    int j = b.size() -1;

    int carry =0;

    while( i >= 0  || j >=0){
        int sum = carry;

        if(i >= 0){
            sum += a[i--] - '0';
        }

        if(j >= 0){
            sum += b[j--] - '0';
        }

        carry = sum > 1?1:0;

        result += to_string(sum %2);
    }

    if(carry){
        result += to_string(carry);
    }

    reverse(result.begin(), result.end());

    return result;




}






// vector<char> decToBinary(int res)
// {
//     vector<char> binaryNum;
//     // int binaryNum[32];
//     int i = 0;
//     while (res > 0) {
//         binaryNum[i] = res % 2;
//         res = res / 2;
//         i++;
//     }
 
//    return binaryNum;
// }


//     string addBinary(string a, string b) {

//         int num1 = 0;
        
//         for(int i=1; i <= a.size(); i++){
//             num1 +=a[a.size()-i]*pow(2,a.size()-i);

           
//         }

//         int num2 = 0;

//            for(int i=1; i <= b.size(); i++){
//             num1 +=b[b.size()-i]*pow(2,b.size()-i);

           
//         }
   
//         int res = num1 + num2;
//         // return to_string(res);

//         string str(decToBinary(res).data(), decToBinary(res).size());
//         return str;


//     }
};

