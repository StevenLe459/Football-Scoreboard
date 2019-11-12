#include "Scoreboard.h"

Scoreboard::Scoreboard(std::string name1, std::string coach1, std::string city1, std::string name2, std::string coach2, std::string city2):home(name1, coach1, city1, true),visitor(name2, coach2, city2, false) {
  min = 0;
  sec = 0;
  quarter = 0;
  down = 0;
  to_go = 0;
  football_status = 0;
}

int Scoreboard::getMin() const {
  return min;
}

int Scoreboard::getSec() const {
  return sec;
}

int Scoreboard::getQuarter() const {
  return quarter;
}

int Scoreboard::getDown() const {
  return down;
}

int Scoreboard::getToGo() const {
  return to_go;
}

int Scoreboard::getFootballStatus() const {
  return football_status;
}

void Scoreboard::setMin(int m) {
  min = m;
}

void Scoreboard::setSec(int s) {
  sec = s;
}

void Scoreboard::setQuarter(int q) {
  quarter = q;
}

void Scoreboard::setDown(int d) {
  down = d;
}

void Scoreboard::setToGo(int t) {
  to_go = t;
}

void Scoreboard::setFootballStatus(int f) {
  football_status = f;
}