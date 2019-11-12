#ifndef COLOR_H
#define COLOR_H
#include <iostream>
#include <string>

std::string set_color(int);
std::string reset_color(int);

std::string set_color(int i) {
  return "\u001b[38;5;" + std::to_string(i) + "m";
}
std::string reset_color() {
  return "\u001b[0m";
}
#endif