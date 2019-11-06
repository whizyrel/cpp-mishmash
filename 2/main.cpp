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
          std::cout << "kindly wait while product menu is being printed...\n";
          break;
        
        case 2:
          std::cout << "checking out your items...\n";
          break;

        case 3:
          std::cout << "exiting and cleaning out garbage...\n";
          std::exit;
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
      std::cout << "   1) Add order to Cart\n";
      std::cout << "   2) Checkout\n";
      std::cout << "   3) Exit\n";
    }

    int saveResponse()
    {
      std::cout << "Enter choice: ";
      std::cin >> this->response;
      std::cout << "you have chosen: " << this->response << "\n";

      this->choiceCtrller();
    }
};

int main()
{
  std::cout << "==========================\n";
  Order _order;
  // _order.showPrompt();
  _order.saveResponse();
  return 0;
}
