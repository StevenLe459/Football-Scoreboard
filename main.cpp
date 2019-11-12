#include "functions.h"

int main() {
  Scoreboard s("Dallas Cowboys", "Jason Garrett", "Dallas", "Houston Texans", "Bill O\'Brien", "Houston");
  std::string option = "";
  do {
    std::cout << "\x1b[2J\x1b[1;1H";
    showScoreboard(s);
    std::cout << "\n" << std::endl;
    showMenu();
    std::cout << "Choose your option: ";
    std::cin >> option;
    handleOption(option, s);
  } while (option != "X" && option != "x"); //DeMorgan's Law
}