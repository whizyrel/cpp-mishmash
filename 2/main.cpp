#include <cstdlib>
#include <iostream>

// using namespace std

/* 
  product/order menu prompt
*/
class Order
{
  private:
    int response;

    void choiceCtrller()
    {
      switch(this->response)
      {
        case 1:
          std::cout << "kindly wait while the list of products is being displayed...\n";
          break;
        
        case 2:
          std::cout << "checking out your items. kindly wait...\n";
          break;

        case 3:
          std::cout << "exiting and cleaning out garbage...\n";
          break;

        default:
          std::cout << "You may have entered an option that doesn't exist\n";
          std::exit;
      }
    }
  
  public:
    void showPrompt()
    {
      // print menu
      std::cout << "What would you like to do?\n";
      std::cout << "use the numbers for your choice selection\n";
      std::cout << "   1) Add more product to your cart\n";
      std::cout << "   2) Checkout\n";
      std::cout << "   3) Exit\n";
      std::cout << "==================================\n";
    }

    void saveResponse()
    {
      std::cout << "Enter choice: ";
      std::cin >> this->response;
      std::cout << "you have chosen option: " << this->response << "\n";

      this->choiceCtrller();
    }
};

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
        std::cout << "You may have chosen a wrong selection. please try again";
      } else if (choice == 'a')
      {
        std::cout << "having your teeth washed... kindly wait";
      } else if (choice == 'b')
      {
        std::cout << "have a nice bath with delta soap!";
      } else if (choice == 'c')
      {
        std::cout << "car engine is being turned on, take off in 5...";
      } else if (choice == 'd')
      {
        std::cout << "Exiting...";
        std::exit;
      }
    }

  public:
    void showPrompt()
    {
      std::cout << "How was your night?\nWhat woul you like have done, first?\n";
      std::cout << "select options between a -> d. invalid options would be ignored!";
      std::cout << "a: brush your teeth";
      std::cout << "b: have your bath";
      std::cout << "c: go to school";
      std::cout << "d: exit menu";
    }

    void collectResponse()
    {
      std::cout << "Enter choice: ";
      std::cin >> this->choice;
      std::cout << "you have chosen option: " << this->choice << "\n";
    }
};

int main()
{
  std::cout << "==========================\n";
  Order _order;

  // _order.showPrompt();
  // _order.saveResponse();


  return 0;
}
