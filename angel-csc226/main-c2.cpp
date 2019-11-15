#include <iostream>

using namespace std;

class votes 
{
  public:
    void voteCount(int choice)
    {

      switch (choice)
      {
        
        case 1:
          cout << "You have voted for 'Adesola'\n";
          break;

        case 2:
          cout << "You have voted for 'Umaru'\n";
          break;

        default:
          cout << "invalid candidate\n";
      }
  };
};

int main() {
  votes num;
  int choice;

  cout << "candidates" << endl;
  cout << "1. Adesola" << endl;
  cout << "2. Umaru" << endl;

  cout << "Enter candidate you would like to vote for: ";
  cin >> choice;
  cout << "\n";

  num.voteCount(choice);

  return 0;
}

