#include<iostream>
using namespace std;


class Solution{
  public:
  //Code here
  long long fibonacci(int N){
    //IF 0th or 1st fobonacci , the return 1
    if(N==0 || N==1) return N ;
    long long prev1 = 1 , prev2 = 0 , curr;
    //use for loop to find Nth fibonacci number
    for(int i=2;i<N;i++){
      curr = prev1 + prev2 ;
      //update 
      prev2 = prev1 ;
      prev1 = curr;
    }

    return prev1 ;
  }

};

int main(){
  //create object
  Solution obj;

  cout<<"Enter which position fibonacci number you want : ";
  int n ;
  cin>>n;

  //IF user enter negative number , then you give a pop up
    if(n<0) {
      cout<<"Enter valid position number"<<endl;
    }

    //If ask valid position
    else{
      cout<<"Fibonacci of "<<n<<"th"<< " positin is : "<<obj.fibonacci(n)<<endl;
    }
  
  return 0;
}