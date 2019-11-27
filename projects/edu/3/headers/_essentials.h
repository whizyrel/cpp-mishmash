#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <fstream>
#include <bits/stdc++.h>
#include <sys/stat.h>
#include <sys/types.h>

namespace _essentials {
  bool pathExists(const std::string &path)
  {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
  };

  void read_file(std::string path)
  {

  };

  bool write_to_file(std::string text, std::string fn)
  {
    std::fstream fs;

    fs.open(fn);

    if (fs.is_open(), std::ios::app)
    {
      fs << text << std::endl;
      fs.close();
    } else
    {
      std::cout << "file opening failed, check file again" << std::endl;
      
      fs.close();
    }

    return fs.is_open();
  }
}
