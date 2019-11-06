#include <cstdlib>
#include <iostream>

using namespace std;

class AddTwo
{
  private:
    int a, b;

  public:
    AddTwo(int a, int b)
    {
      this->a = a;
      this->b = b;
    }

    int solve()
    {
      return this->a + this->b;
    }
};

class AddThree
{
  private:
    int a, b, c;

  public:
    AddThree(int a, int b, int c)
    {
      this->a = a;
      this->b = b;
      this->c = c;
    }

    int solve()
    {
      return this->a + this->b + this->c;
    }
};

int main() 
{
  AddTwo addTwo(4, 4);
  AddThree addThree(2, 2, 2);

  const int sumofTwoNumbers = addTwo.solve();
  const int sumofThreeNumbers = addThree.solve();

  int sum = sumofThreeNumbers + sumofTwoNumbers;

  cout << "===================================\n";
  cout << "\n";

  cout << "The sum of two numbers is: " << sumofTwoNumbers << "\n";
  cout << "The sum of two numbers is: " << sumofThreeNumbers << "\n";
  cout << "The sum of all numbers is: " << sum << '\n';

  cout << "\n";  
  cout << "===================================\n";

  return 0;
}
