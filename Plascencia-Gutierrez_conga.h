#pragma once
#ifndef CONGA_H
#define CONGA_H
#include "Plascencia-Gutierrez_list.h"
#include "Plascencia-Gutierrez_zombie.h"

//For information on Class see .cpp file

class Conga{
private:
  LinkedList<Zombie*>* congaLine;
  static char colors[6];
  void engine(Zombie*);
  void caboose(Zombie*);
  void jump(Zombie*);
  void out(Zombie*);
  void done(Zombie*);
  void brains(Zombie*,char);
  void rainbow(Zombie*);
  void random();
  void cut();
  
public:
  Conga();
  ~Conga();
  void round(int);
  bool isEmpty();
  
};

#endif
