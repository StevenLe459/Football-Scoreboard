#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include "Scoreboard.h"
#include "color.h"
#include "input_validation.h"
#include <iostream>
#include <iomanip>

//Function prototypes
void showScoreboard(Scoreboard);
void showMenu();
void showHomeMenu();
void showVisitorMenu();
void handleOption(std::string, Scoreboard&);
void handleHomeOption(std::string, Scoreboard&);
void handleVisitorOption(std::string, Scoreboard&);

void showScoreboard(Scoreboard s) {
  std::cout << set_color(124) << "------------------------------------------------------------------------" << std::endl;
  std::cout << "| "  << set_color(39) << "HOME                        " << set_color(124) << "| " << set_color(11) << std::right << std::setw(3) << std::setfill('0') << s.getMin() << ":" << std::setw(2) << std::setfill('0') << s.getSec() << set_color(124) << " |                       "<< set_color(39) << "VISITOR" << set_color(124) << " |" << std::endl << std::setfill(' ');
  std::cout << "|                             ----------                               |" << std::endl;
  std::cout << "| " << set_color(207) << std::left << std::setw(34) << s.home.getName() << std::right << std::setw(34) << s.visitor.getName() << set_color(124) << " |" << std::endl; 
  std::cout << "| " << set_color(203) << std::left << std::setw(34) << s.home.getCoachName() << std::right << std::setw(34) << s.visitor.getCoachName() << set_color(124) << " |" << std::endl;
  std::cout << "| " << set_color(191) << std::left << std::setw(34) << s.home.getHomeCity() << std::right << std::setw(34) << s.visitor.getHomeCity() << set_color(124) << " |" << std::endl;
  std::cout << "|------                           -----                          ------|" << std::endl;
  if (s.getFootballStatus() == 0 ) {
    std::cout << "|     |                        " << set_color(105) << "QTR" << set_color(124) << "| " << set_color(105) << s.getQuarter() << set_color(124) << " |" << "                          |     |" << std::endl;
  }

  else if (s.getFootballStatus() == 1) {
    std::cout << "|  " << set_color(27) << "*" << set_color(124) <<  "  |                        " << set_color(105) << "QTR" << set_color(124) << "| " << set_color(105) << s.getQuarter() << set_color(124) << " |" << "                          |     |" << std::endl;
  }

  else {
    std::cout << "|     |                        " << set_color(105) << "QTR" << set_color(124) << "| "  << set_color(105) << s.getQuarter() << set_color(124) << " |" << "                          |  "<< set_color(27) << "*" << set_color(124) << "  |" << std::endl;
  }
  std::cout << "|------                           -----                          ------|" << std::endl;
  std::cout << "|----------                                                  ----------|" << std::endl;
  std::cout << "| " << set_color(47) << std::left << std::setw(8) << s.home.getScore() << set_color(124) << "|--------------------- " << set_color(47)<< "SCORES"<< set_color(124) << " ---------------------|" << set_color(47) << std::right << std::setw(8) << s.visitor.getScore() << set_color(124) << " |" << std::endl;
  std::cout << "|----------                                                  ----------|" << std::endl;
  std::cout << "|----------                                                  ----------|" << std::endl;
  std::cout << "| " << set_color(93) << std::left << std::setw(8) << s.home.getTimeoutCount() << set_color(124) << "|-------------------- " << set_color(93) << "TIMEOUTS" << set_color(124) << " --------------------|" << set_color(93) << std::right << std::setw(8) <<s.visitor.getTimeoutCount() << set_color(124) << " |" << std::endl;
  std::cout << "|----------                                                  ----------|" << std::endl;
  std::cout << "|----------                                                  ----------|" << std::endl;
  std::cout << "| " << set_color(3) << std::left << std::setw(8) << s.getToGo() << set_color(124) << "| " << set_color(3) << "TO GO" << set_color(174) << "                                       DOWN" << set_color(124) << " |" << set_color(174) << std::right << std::setw(8) <<s.getDown() << set_color(124) << " |" << std::endl;
  std::cout << "|----------                                                  ----------|" << std::endl;
  std::cout << "------------------------------------------------------------------------" << std::endl; 
}

void showMenu() {
  std::cout << set_color(33);
  std::cout << "Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "Option A: Edit Home Team Information" << std::endl;
  std::cout << "Option B: Edit Visitor Team Information" << std::endl;
  std::cout << "Option C: Edit Time" << std::endl;
  std::cout << "Option D: Edit Quarter" << std::endl;
  std::cout << "Option E: Edit Down" << std::endl;
  std::cout << "Option F: Edit To Go" << std::endl;
  std::cout << "Option G: Edit Football Status" << std::endl;
  std::cout << "Option X: Exit" << std::endl;
}

void showHomeMenu() {
  std::cout << set_color(46);
  std::cout << "Home Team Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "Option A: Edit Home Team Name" << std::endl;
  std::cout << "Option B: Edit Home Team Coach" << std::endl;
  std::cout << "Option C: Edit Home Team City" << std::endl;
  std::cout << "Option D: Edit Home Team Score" << std::endl;
  std::cout << "Option E: Edit Home Team Timeout Count" << std::endl;
  std::cout << "Option X: Return" << std::endl;
}

void showVisitorMenu() {
  std::cout << set_color(129);
  std::cout << "Visitor Team Menu" << std::endl;
  std::cout << "-------------------------------" << std::endl;
  std::cout << "Option A: Edit Visitor Team Name" << std::endl;
  std::cout << "Option B: Edit Visitor Team Coach" << std::endl;
  std::cout << "Option C: Edit Visitor Team City" << std::endl;
  std::cout << "Option D: Edit Visitor Team Score" << std::endl;
  std::cout << "Option E: Edit Visitor Team Timeout Count" << std::endl;
  std::cout << "Option X: Return" << std::endl;
}

void handleOption(std::string option, Scoreboard& s) {
  std::string o = "";
  int i = 0;
  if (option == "A" || option == "a") {
    showHomeMenu();
    std::cout << "Please enter your option: ";
    std::cin >> o;
    handleHomeOption(o, s);
  }
  else if (option == "B" || option == "b") {
    showVisitorMenu();
    std::cout << "Please enter your option: ";
    std::cin >> o;
    handleVisitorOption(o, s);
  }
  else if (option == "C" || option == "c") {
    do {
      std::cout << "For minutes, please enter an integer between 0 and 999." << std::endl;
      i = validateInt(i);
      if (i < 0 || i > 999) {
        std::cout << "Integer must be between 0 and 999." << std::endl;
      }
    } while(i < 0 || i > 999);
    s.setMin(i);
    do {
      std::cout << "For seconds, please enter an integer between 0 and 59." << std::endl;
      i = validateInt(i);
      if (i < 0 || i > 59) {
        std::cout << "Integer must be between 0 and 59." << std::endl;
      }
    } while(i < 0 || i > 59);
    s.setSec(i);
  }
  else if (option == "D" || option == "d") {
    do {
      std::cout << "Please enter an integer between 0 and 9." << std::endl;
      i = validateInt(i);
      if (i < 0 || i > 9) {
        std::cout << "Integer must be between 0 and 9." << std::endl;
      }
    } while (i < 0 || i > 9);
    s.setQuarter(i);
  }
  else if (option == "E" || option == "e") {
    std::cout << "Please enter an integer." << std::endl;
    i = validateInt(i);
    s.setDown(i);
  }
  else if (option == "F" || option == "f") {
    std::cout << "Please enter an integer." << std::endl;
    i = validateInt(i);
    s.setToGo(i);
  }
  else if (option == "G" || option == "g") {
    std::cout << "0: No Team has the Football" << std::endl;
    std::cout << "1: Home Team has Football" << std::endl;
    std::cout << "2: Visitor Team has Football" << std::endl;
    do {
      std::cout << "Please enter your option (must be an integer)." << std::endl;
      i = validateInt(i);
      if (i < 0 || i > 2) {
        std::cout << "Please enter a valid option." << std::endl;
      }
    } while(i < 0 || i > 2);
    s.setFootballStatus(i);
  }
  else if (option == "X" || option == "x") {
    std::cout << "Goodbye!" << std::endl;
  }
  else {
    std::cout << "Invalid option." << std::endl;
  }
}

void handleHomeOption(std::string option, Scoreboard& s) {
  std::string str;
  int i = 0;
  if (option == "A" || option == "a") {
    std::cin.ignore();
    std::cout << "Enter the name: ";
    std::getline(std::cin, str);
    s.home.setName(str);
  }
  else if (option == "B" || option == "b") {
    std::cin.ignore();
    std::cout << "Enter the coach name: ";
    std::getline(std::cin, str);
    s.home.setCoachName(str);
  }
  else if (option == "C" || option == "c") {
    std::cin.ignore();
    std::cout << "Enter the city: ";
    std::getline(std::cin, str);
    s.home.setHomeCity(str);
  }
  else if (option == "D" || option == "d") {
    std::cout << "Please enter an integer." << std::endl;
    i = validateInt(i);
    s.home.setScore(i);
  }
  else if (option == "E" || option == "e") {
    std::cout << "Please enter an integer." << std::endl;
    i = validateInt(i);
    s.home.setTimeoutCount(i);
  }
  else if (option == "X" || option == "x") {
    ;
  }
  else {
    std::cout << "Invalid option." << std::endl;
  }
}

void handleVisitorOption(std::string option, Scoreboard& s) {
  std::string str;
  int i = 0;
  if (option == "A" || option == "a") {
    std::cin.ignore();
    std::cout << "Enter the name: ";
    std::getline(std::cin, str);
    s.visitor.setName(str);
  }
  else if (option == "B" || option == "b") {
    std::cin.ignore();
    std::cout << "Enter the coach name: ";
    std::getline(std::cin, str);
    s.visitor.setCoachName(str);
  }
  else if (option == "C" || option == "c") {
    std::cin.ignore();
    std::cout << "Enter the city: ";
    std::getline(std::cin, str);
    s.visitor.setHomeCity(str);
  }
  else if (option == "D" || option == "d") {
    std::cout << "Please enter an integer." << std::endl;
    i = validateInt(i);
    s.visitor.setScore(i);
  }
  else if (option == "E" || option == "e") {
    std::cout << "Please enter an integer." << std::endl;
    i = validateInt(i);
    s.visitor.setTimeoutCount(i);
  }
  else if (option == "X" || option == "x") {
    ;
  }
  else {
    std::cout << "Invalid option." << std::endl;
  }
}
#endif