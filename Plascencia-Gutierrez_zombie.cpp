#include <iostream>
#include "termcolor.hpp"
#include "Plascencia-Gutierrez_zombie.h"
/*
  Name: Zombie
  Desc: Zombies hold a character and have overloaded == and <<
 */

Zombie::Zombie(char c){//Stores Color of Zombie
  color = c;
}

bool operator== (const Zombie &z1, const Zombie &z2){//Checks if Zombies are the same
  if(z1.color == z2.color){
    return true;
  }else{
    return false;
  }
}

std::ostream & operator<< (std::ostream &out, const Zombie &z){//Prints Colored text of zombie
  switch(z.color){
  case 'R':
    out<< termcolor::red << '[' << z.color << ']' << termcolor::reset;
    return out;
    break;
  case 'Y':
    out<< termcolor::yellow << '[' << z.color << ']' << termcolor::reset;
    return out;
      break;
  case 'G':
    out<< termcolor::green << '[' << z.color << ']' << termcolor::reset;
    return out;
    break;
  case 'B':
    out<< termcolor::blue<< '[' << z.color << ']' << termcolor::reset;
    return out;
    break;
  case 'M':
    out<< termcolor::magenta << '[' << z.color << ']' << termcolor::reset;
    return out;
    break;
  case 'C':
    out<< termcolor::cyan << '[' << z.color << ']' << termcolor::reset;
    return out;
    break;
  default:
    out << "";
    return out;
    break;
  }
}
