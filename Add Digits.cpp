// class Solution {
// public:
//     int addDigits(int num) {

//          int sum =0;
//     while(num){
//         sum += num%10;
//         num = num /10;
//     }
//       if(sum<9)
//           return sum;
      

//       else
//           return addDigits(sum);



      
//     }
// };

class Solution{
    public:

    int addDigits(int num) {
	if ( num == 0 ) return 0;
	return num%9 == 0 ? 9 : num%9 ;
}
};


