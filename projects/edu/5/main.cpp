/* 
question
=====================================================
Write a C++ application that calculates the wages of staff for a company called EPSILON
computers. The are two categories of staff in the company, junior and senior staff. The
normal working hours for any staff is 40 hours. The hourly rate for overtime is 1.5 times the
normal rate for junior staff and 2.0 times the normal rate for senior staff. Note that no one is
allowed to do more than maximum of 70 hours per week. The normal pay rate for junior
staff is 200 naira per hour for junior staff and 300 naira per hour for senior staff. Your
application must be able to read information from a file and write output into a file. Test
with 50 staff.
====================================================
*/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "headers/worker.h"

using namespace std;

int fol_stats = mkdir("./files", 0777);

bool pathExists(const std::string &path)
{
  struct stat buffer;
  return (stat(path.c_str(), &buffer) == 0);
}

void read_file(string path)
{

};

void write_to_file(int no, string name, string type, double ts, string fn)
{
  fstream fs;
  ostringstream oss;
  ostringstream oss_fn;

  oss_fn << "files/" << fn << ".csv";
  string path = oss_fn.str();

  fs.open(path, ios::app);

  oss << to_string(no) << "," << name << "," << type << "," << to_string(ts) << endl;
  string line = oss.str();

  /* strcat((char*)(line.c_str()), to_string(no).c_str());
  line = strcat((char *)(line.c_str()), type.c_str());
  line = strcat((char *)(line.c_str()), to_string(ts).c_str()); */

  if (pathExists("files/"))
  {
    // write data to file
    fs << line;
    fs.close();

    return;
  } else {
    cout << "directory does not exist!" << endl;

    fol_stats = mkdir("./files", 0777);
    write_to_file(no, name, type, ts, fn);
    
    fs.close();
  }
};

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

int main()
{
  string filename;
  string content;
  string result_fn;
  fstream fs;

  cout << "=================================" << endl;
  cout << "Please enter the path (relative) to the file: ";
  cin >> filename;

  cout << "what would you like to save the result as?: ";
  cin >> result_fn;

  cout << "opening file..." << endl;
  cout << "=================================" << endl;
  fs.open(filename);

  cout << "file opening status: " << (
    fs.is_open() ? 
  "success: file opened" : 
  "failed: could not open file"
  ) << endl;

  if (fs.is_open())
    {
      cout << "file opened!" << endl;

      int count = 0;
      string header;

      for (content; getline(fs, content); count++)
      {

        header = "S/N, NAME, TYPE, PAYCHECK";

        if (count != 0) {
          string parsed;
          // iterate...
          // write header to file
          std::stringstream _sstream(content);
          int i;
          string type, name;
          int  n_hrs, o_hrs;

          for (parsed, i = 0; getline(_sstream, parsed, ','); i++)
          {
            if (i == 1)
              name = parsed;

            if (i == 2)
              n_hrs = atoi(parsed.c_str());

            if (i == 3)
              type = parsed;

            if (i == 4)
              o_hrs = atoi(parsed.c_str());
          }

          worker::Worker _worker;
          _worker.set_data(type, name, n_hrs, o_hrs);
          const int pay = _worker.calculate_pay();

          write_to_file(count, name, type, pay, result_fn);
        }
      }
    }
  else
  {
    cout << "warning: file not found" << endl;
  }

  cout << "folder creation status: " << fol_stats << endl;

  fs.close();

  return 0;
}
