/* 
  Aggregation - UTME, LASU SCORE, WAEC RESULT
  cut-off = 52%;
  max post_utme = 50, max utme = 400
  O/L result from 5 best subjects

  Aggregate = 0.0625 * UME score + 0.50 * GCE-O/L score + 0.50 * post–UME score

  O/L score = Total O/L point + Sitting point
  C6 = 3, C5 = 4, C4 = 5, B3 (A3) = 6, B2 (A2) = 7, A1 = 8
  max sitting = 2
  1 sitting = 10 points 
  2 sittings = 5 points

  100 students
  read from file and write to file
*/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "./headers/utilities.h"

using namespace std;
using namespace utilities;

int main()
{
  fstream rfs; // result file opening fstream

  const string header = "S/N,NAME,AGGREGATE,ADMISSION STATUS";
  const string filepath = "./resources/results.csv";
  const string results_dir = "scores";
  string line;

  int count = 0, sitting_no = 1;

  cout << "*****************************************************************" << endl;
  cout << "                         Admission Module                        " << endl;
  cout << "preparing application environment" << endl;

  mkdir(results_dir.c_str(), 0777);

  // receive file path relative to main.cpp
  // receive folder directory to save file
  // score filename
  // receive number of sittings
  cout << "How many sittings (maximum no of sittings is 2): " << sitting_no << endl;

  // open file for reading
  rfs.open(filepath);

  if (rfs.is_open())
  {
    cout << "file was opened successfully!" << endl;

    // read file
    for (count, line; getline(rfs, line, '\n'); count++)
    {
      // cout << "line: " << line << endl;
      string name, ol_result;
      int utme, post_utme;

      stringstream lfs(line); // line string stream

      if (count != 0)
      {
        // split line by comma
        string row;
        int i;

        for (row, i = 0; getline(lfs, row, ','); i++)
        {
          // cout << "each row: " << row << endl;

          if (i == 1)
          {
            name = row;
          }

          if (i == 2)
          {
            ol_result = row;
          }

          if (i == 3)
          {
            utme = atol(row.c_str());
          }

          if (i == 4)
          {
            post_utme = atol(row.c_str());
          }
        }
      }

      const int total_ol_score = calc_ol_result(ol_result);
      cout << "total O'level score: " << total_ol_score << endl;
    }
    } else 
  {
    cout << "Error: file was not opened successfully" << endl;
  }

  rfs.close();
}
