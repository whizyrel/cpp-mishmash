#include <cstdlib>
#include <iostream>
#include <string>

/*
*** EPSILON Wage Calculator ***
* types of staff
  - junior staff
  - senior staff
* normal working hours - 40
* maximum working hours - 70
* max overtime hours - 30
* normal hours rate (j, s) - (200, 300)
* overtime hours (j, s) - (1.5 * 200, 2.0 * 300)
* read from file, output from file
* minimum 50 staff
*/

namespace worker {
  class Worker
  {
    private:
      int o_hrs;
      int n_hrs;

      std::string name;
      std::string _type;

      int o_rate;
      int n_rate;
      int max_o_hours = 30;
      int min_n_hours = 40;
      int total_sum;
      int overtime_sum;
      int normal_sum;

      void set_normal_rate()
      {
       if (this->_type == "junior")
        {
          this->n_rate = 200;
          
          return;
        }
        else if (this->_type == "senior")
        {
          this->n_rate = 300;

          return;
        }

        throw "Invalid worker type";
      }

      void set_overtime_rate() 
      {
       if (this->_type == "junior")
        {
          this->o_rate = 200 * 1.5;

          return;
        }
        else if (this->_type == "senior")
        {
          this->o_rate = 300 * 2;

          return;
        }

        throw "Invalid worker type";
      }

      int calc_normal_sum(int hrs)
      {
        this->normal_sum = this->n_rate * hrs;

        return this->normal_sum;
      }

      int calc_overtime_sum(int hrs)
      {
        this->overtime_sum = this->o_rate * hrs;

        return this->overtime_sum;
      }

    public:
      void set_data(
        std::string _type, 
        std::string name, 
        int n_hrs, 
        int o_hrs
        )
      {
        this->name = name; 
        this->_type = _type;
        this->o_hrs = o_hrs;
        this->n_hrs = n_hrs;

        this->set_normal_rate();
        this->set_overtime_rate();
      }

      double calculate_pay()
      {
        if (this->n_hrs < 40)
        {
          std::cout << this->name << " has not worked mininum number of hours: ";
          std::cout << this->min_n_hours << std::endl;
          
          return 0.00;
        }

        if (this->n_hrs + this->o_hrs > 70) {
          this->n_hrs = 40;
          this->o_hrs = 30;
        }

        this->total_sum = this->calc_normal_sum(this->n_hrs) + this->calc_overtime_sum(this->o_hrs);

        return this->total_sum;
      }
  };  
}
