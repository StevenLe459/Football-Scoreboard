#include "Team.h"

Team::Team(std::string n, std::string cn, std::string hc, bool hs) {
  name = n;
  coach_name = cn;
  home_city = hc;
  home_status = hs;
  score = 0;
  timeout_count = 0;
}

std::string Team::getName() const {
  return name;
}

std::string Team::getCoachName() const {
  return coach_name;
}

std::string Team::getHomeCity() const {
  return home_city;
}

bool Team::getHomeStatus() const {
  return home_status;
}

int Team::getScore() const {
  return score;
}

int Team::getTimeoutCount() const {
  return timeout_count;
}

void Team::setName(std::string n) {
  name = n;
}

void Team::setCoachName(std::string c) {
  coach_name = c;
}

void Team::setHomeCity(std::string h) {
  home_city = h;
}

void Team::setHomeStatus(bool h) {
  home_status = h;
}

void Team::setScore(int s) {
  score = s;
}

void Team::setTimeoutCount(int t) {
  timeout_count = t;
}