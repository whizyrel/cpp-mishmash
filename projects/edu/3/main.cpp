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
#include "./headers/_essentials.h"

using namespace std;
using namespace utilities;
using namespace _essentials;

int main()
{
  fstream rfs; // result file opening fstream

  const string header = "S/N,NAME,AGGREGATE,ADMISSION STATUS";
  // const string filepath = "resources/results.csv";
  // const string results_dir = "scores";
  string  filepath, results_dir;
  string line, fn;

  int count = 0;

  cout << "*****************************************************************" << endl;
  cout << "                         Admission Module                        " << endl;
  cout << "preparing application environment..." << endl;

  // receive file path relative to main.cpp
  cout << "Please enter the relative path to the input file: ";
  cin >> filepath;

  // receive folder directory to save file
  cout << "Output directory: ";
  cin >> results_dir;

  mkdir(results_dir.c_str(), 0777);

  // score filename
  cout << "What would you like to save the file as? ";
  cin >> fn;

  // open file for reading
  rfs.open(filepath);

  if (rfs.is_open())
  {
    cout << "file was opened successfully!" << endl;
    ostringstream rfps; // result filepath stream
    rfps << results_dir << "/" << fn << ".csv";

    cout << rfps.str() << endl;

    // write header first
    cout << "header writing status: " << write_to_file(header, rfps.str() /* "scores/file.csv" */) << endl;

    // read file
    for (count, line; getline(rfs, line, '\n'); count++)
    {
      // cout << "line: " << line << endl;
      string name, ol_result, adm_status;
      int utme, post_utme, s_no;

      stringstream lfs(line); // line string stream

      if (count != 0)
      {
        // split line by comma
        string row;
        int i;

        for (row, i = 0; getline(lfs, row, ','); i++)
        {
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

          if (i == 5)
          {
            s_no = atol(row.c_str());
          }
        }

        const int total_ol_score = calc_ol_result(ol_result, s_no);
        // cout << "Total O'Level score: " << total_ol_score << endl;

        // calc aggregate      
        const double aggregate = calc_aggregate(utme, post_utme, total_ol_score);

        // get admission status
        adm_status = get_admission_status(aggregate);

        ostringstream ors; // output result stream

        ors << count << "," << name << "," << aggregate <<  "," << adm_status;

        // write result to file
        write_to_file(ors.str(), rfps.str());
      }

      cout << rfps.str() << endl;
    }
  } else 
  {
    cout << "Error: file was not opened successfully" << endl;
  }

  rfs.close();

  return 0;
}
