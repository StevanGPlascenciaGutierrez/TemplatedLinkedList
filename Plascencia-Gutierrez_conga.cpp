#include <string>
#include <iostream>
#include "Plascencia-Gutierrez_list.h"
#include "Plascencia-Gutierrez_zombie.h"
#include "Plascencia-Gutierrez_conga.h"
/*
  Name:Conga
  Desc:Holds a LinkedList of Zombie* nodes, forms a Conga Line and contains several methods for using Conga Line
 */
Conga::Conga(){//Constructor
  congaLine = new LinkedList<Zombie*>();
  int zNum, actionAmt;
  char color;
  Zombie* firstZombie;
  Zombie* newZombie;

  
  //Generates First Zombie
  zNum = rand() % 6;
  color = colors[zNum];
  firstZombie = new Zombie(color);

  //Start Conga Line
  rainbow(firstZombie);
  
  //Random Amount of Brain! actions
  actionAmt = (rand() % 4) + 2;
  for(int i = 0; i < actionAmt; i++){
    zNum = rand() % 6;
    color = colors[zNum];
    newZombie = new Zombie(color);
    brains(newZombie, color);
  }

}

Conga::~Conga(){//Destructor
  delete congaLine;
}

char Conga::colors[6] = {'R','Y','G','B','M','C'};//Array of Zombie Colors

void Conga::round(int roundNum){
  std::cout << "Round " << roundNum << "\n";
  std::cout << "The Zombie Party keeps on groaning! \n";
  congaLine->printList();
  std::cout << " \n";
  random();
  congaLine->printList();
  std::cout << " \n";
  std::cout <<"*******************************************\n\n\n";

  if((roundNum % 5 == 0)&&(roundNum!=0)){
    cut();
  }
}

bool Conga::isEmpty(){
  if(congaLine->length() <= 0){
    return true;
  }
  return false;
}

/*----------Private Methods -----------*/
void Conga::random(){//Creates Random Zombie then Exectutes Random Action
  int zNum, actionNum;
  char color;
  Zombie* zombie;

  zNum = rand() % 6;//Generates Number to Decide Zombie Color
  actionNum = rand() % 7;//Generates Number to Decide Zombie Action

  color = colors[zNum];

  zombie = new Zombie(color);

  switch(actionNum){//Switch Statement to Call Random action
  case 0:
    std::cout<<"VROOOOOM!" << color << " zombie revs up to the front! (ENGINE!)\n"; 
    engine(zombie);
    break;
  case 1:
    std::cout << "CHOO CHOO! " << color << " zombie comes from behind! (CABOOSE!)\n";
    caboose(zombie);
    break;
  case 2:
    std::cout << "APACHE JUMP ON IT! " << color << " zombie jumps in line! (JUMP!)\n";
    jump(zombie);
    break;
  case 3:
    std::cout << "EVEYONE OUT! " << color << " zombies get out of line! (Everyone Out!)\n";
    out(zombie);
    break;
  case 4:
    std::cout <<"YOU'RE DONE! The first "<< color << " zombie gets out of line! (You're Done!)\n";
    done(zombie);
    break;
  case 5:
    std::cout << "BRRRRAINS! "<< color << " zombie brings his friends to the party! (BRAINS!)\n";
    brains(zombie, color);
    break;
  case 6:
    std::cout << "DON'T STOP ME NOW! "<< color << " zombie rides a rainbow to the party!  (Rainbow Brains!)\n";
    rainbow(zombie);
    break;
  }  
}

void Conga::engine(Zombie* zombie){//Puts zombie up front
  congaLine->addToFront(zombie);
}

void Conga::caboose(Zombie* zombie){//Zombie is placed in back
  congaLine->addToEnd(zombie);
}

void Conga::jump(Zombie* zombie){//Zombie jumps randomly into Line
  int index, length; 
  length = congaLine->length();
  index = rand() % length;
  congaLine->addAtIndex(zombie, index);
}

void Conga::out(Zombie* zombie){//Removes All matching zombies
  congaLine->removeAllOf(zombie);
}

void Conga::done(Zombie* zombie){//Removes the First zombie of the same color
  congaLine->removeTheFirst(zombie);
}

void Conga::brains(Zombie* zombie, char color){//Adds zombie to front, one in th middle, and one more to the back
  Zombie* secondZombie = new Zombie(color);
  Zombie* thirdZombie = new Zombie(color);
  int index = (congaLine->length() / 2);
  congaLine->addToFront(zombie);
  congaLine->addAtIndex(secondZombie,index);
  congaLine->addToEnd(thirdZombie);
}

void Conga::rainbow(Zombie* zombie){//Adds Zombie to front and one of each to back
  congaLine->addToFront(zombie);
  for(int i = 0; i < 6; i++){
    Zombie* newZombie = new Zombie(colors[i]);
    congaLine->addToEnd(newZombie);
  }
}

void Conga::cut(){//Cuts front and End
  if(this->isEmpty()){
    return;
  }
  congaLine->removeFromFront();
  congaLine->removeFromEnd();
}
