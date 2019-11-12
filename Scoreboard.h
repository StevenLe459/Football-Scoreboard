#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include "Team.h"

class Scoreboard {
  public:
    Team home;
    Team visitor;
  private:
    int min;
    int sec;
    int quarter;
    int down;
    int to_go;
    int football_status; //shows which team has football
  public:
    Scoreboard(std::string, std::string, std::string, std::string, std::string, std::string);
    int getMin() const;
    int getSec() const;
    int getQuarter() const;
    int getDown() const;
    int getToGo() const;
    int getFootballStatus() const;
    void setMin(int);
    void setSec(int);
    void setQuarter(int);
    void setDown(int);
    void setToGo(int);
    void setFootballStatus(int);
};
#endif