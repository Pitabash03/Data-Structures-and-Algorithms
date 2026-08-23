#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n = cardPoints.size();
        int leftsidesum=0 , rightsidesum=0 , sum = 0;
        for(int i=0;i<k;i++){
          leftsidesum = leftsidesum + cardPoints[i];
          sum = leftsidesum ;
        }
        int rightIndex = n-1;
        for(int j=k-1 ; j>=0 ;j--){
          leftsidesum = leftsidesum - cardPoints[j];
          rightsidesum = rightsidesum + cardPoints[rightIndegix];
          rightIndex--;
          sum = max(sum , leftsidesum + rightsidesum);
        }

        return sum;
    }
};


int main(){
  Solution obj ;
  vector<int>arr = {2 , 9 , 7 , 3, 9 , 8 , 1};
  int k = 4;
  cout<<"maximum points is : "<<obj.maxScore(arr,k);
  return 0;
}