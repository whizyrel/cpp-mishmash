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
  }
}
