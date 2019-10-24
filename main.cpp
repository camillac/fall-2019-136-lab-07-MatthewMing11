#include <iostream>
#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#include "funcs.h"

int main(int argc, char *argv[])
{
  // your code here
  std::cout<<"Testing ascii function from main:"<<std::endl;
  ascii("Cat :3 Dog");
  return 0;
}
