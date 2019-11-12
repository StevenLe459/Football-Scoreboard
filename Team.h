#ifndef TEAM_H
#define TEAM_H
#include <string>

class Team {
  private:
    std::string name;
    std::string coach_name;
    std::string home_city;
    bool home_status;
    int score;
    int timeout_count;
  public:
    Team(std::string, std::string, std::string, bool);
    std::string getName() const;
    std::string getCoachName() const;
    std::string getHomeCity() const;
    bool getHomeStatus() const;
    int getScore() const;
    int getTimeoutCount() const;
    void setName(std::string);
    void setCoachName(std::string);
    void setHomeCity(std::string);
    void setHomeStatus(bool);
    void setScore(int);
    void setTimeoutCount(int);
};
#endif