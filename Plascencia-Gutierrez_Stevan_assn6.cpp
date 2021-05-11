#include <iostream>
#include <string>
#include <ctime>
#include "Plascencia-Gutierrez_node.h"
#include "Plascencia-Gutierrez_list.h"
#include "Plascencia-Gutierrez_zombie.h"
#include "Plascencia-Gutierrez_conga.h"
#include "termcolor.hpp"
using namespace std;

/* 
Author:Stevan Plascencia-Guiterrez
Date: 4/19/21
Description: Creates conga line of colored zombies and creates random events for as long as the user wants or until conga empties
*/

int main(){
  srand((unsigned) time(0));
  
  Conga* party = new Conga();
  int roundAmt, curRound, userInput;
  curRound = 0;
  roundAmt = -1;
  do{//Loop to Keep Conga going

    while(roundAmt == -1){//While Loop to verify round is Int
      cout << "How many rounds do you want to run? Enter a number 0 or more\n";
      if(!(cin >> userInput)){
	cout<< "Enter a valid number #\n";
	cin.clear();
	cin.ignore();
	roundAmt = -1;
      }else if(userInput >= 0 ){
	roundAmt = userInput;
      }
    }//End Of Check
    
    
    while(curRound <= roundAmt){//Loop to run Rounds
      
      party->round(curRound);
      curRound++;
      
      if(party->isEmpty()){
	cout << "Part is Over!\n";
	return 0;
      }
    }

    while(roundAmt <= curRound){//While Loop to see if user wants to continue
      cout << "Keep the party going? \n\t -Enter a number Greater than 0 to Continue \n\t -Enter 0 to end party \n";
      if(!(cin >> userInput)){
	cout<< "Enter a valid number #\n";
	cin.clear();
	cin.ignore();
      }else if(userInput > 0){
	roundAmt = userInput + curRound;
      }else if(userInput == 0){
	cout << "Party is Over!\n";
	return 0;
      }
    }; //End Of Check
    
    
  }while(roundAmt != 0);//End of Conga
  
  
  return 0;
}
