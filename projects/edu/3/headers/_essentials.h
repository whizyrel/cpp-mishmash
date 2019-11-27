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

  bool write_to_file(std::string text, std::string fp)
  {
    std::fstream _rfs;

    _rfs.open(fp, std::ios::app);

    std::cout << "file path: " << fp  << std::endl;
    if (_rfs.is_open())
    {
      _rfs << text << std::endl;
      _rfs.close();
    } else
    {
      std::cout << "file opening failed, check file again" << std::endl;
      
      _rfs.close();
    }

    return _rfs.is_open();
  }
}
