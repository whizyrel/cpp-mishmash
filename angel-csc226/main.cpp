/* 
    
    code 1
 */
#include<iostream>

using namespace std;

/*
*
*/
class investorClass
{
  
  public:
    int investor;
    void investorNum()
    {
      if (this->investor < 10){
        cout << "NUmber of invstors are not enough we need up to 50 invstors";
      } else if (this->investor <= 20){
        cout << "Number of investors is not bad, but needs to meetup with the benchmak of 50 and above";
      } else if (this->investor <= 50){
        cout << "Good, we are not short of investors you've done a great job";
      } else if (this->investor > 50) {
        cout << "We have more than enough investors, this is okay thank you";
      } else {
        cout << "You didn't enter a valid number";
      }
    }
};


int main() {
  investorClass inv;
  cout << "Enter your number of investors";
  cin >> inv.investor;
  inv.investorNum();
  return 0;
}








