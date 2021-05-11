#pragma once
#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <iostream>
#include "termcolor.hpp"

//See .cpp for more information 
class Zombie{
 private:
  char color;

 public:
  Zombie(char);
  friend bool operator== (const Zombie&, const Zombie&);
  friend std::ostream& operator<< (std::ostream& , const Zombie&);
  
};

#endif
