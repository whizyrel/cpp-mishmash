#include <cstdlib>
#include <iostream>

/* 
  day menu
*/
class DayMenu
{
  private:
    char choice;

    void takeAction()
    {
      char choice = this->choice;

      if (
        choice != 'a' &&
        choice != 'b'&&
        choice != 'c' &&
        choice != 'd'
        )
      {
        std::cout << "You may have chosen a wrong selection. please try again\n";
      } else if (choice == 'a')
      {
        std::cout << "having your teeth washed... kindly wait\n";
      } else if (choice == 'b')
      {
        std::cout << "have a nice bath with delta soap!\n";
      } else if (choice == 'c')
      {
        std::cout << "car engine is being turned on, take off in 5...\n";
      } else if (choice == 'd')
      {
        std::cout << "Exiting...\n";
        std::cout << "=========================\n";
        std::exit;
      }
    }

  public:
    void showPrompt()
    {
      std::cout << "Hi! How was your night?\nWhat would you have done, first?\n";
      std::cout << "select options between a to d. invalid options would be ignored!\n";
      std::cout << "======================\n";
      std::cout << "a: brush your teeth\n";
      std::cout << "b: have your bath\n";
      std::cout << "c: go to school\n";
      std::cout << "d: exit menu\n";
    }

    void collectResponse()
    {
      std::cout << "Enter choice: ";
      std::cin >> this->choice;
      std::cout << "you have chosen option: '" << this->choice << "'\n";
      this->takeAction();
    }
};

int main()
{
  std::cout << "==========================\n";
  DayMenu _dayMenu;

  _dayMenu.showPrompt();
  _dayMenu.collectResponse();

  return 0;
}
