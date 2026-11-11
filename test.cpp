#include <iostream>
#include "upl.hpp"

int main() {
  Console con;
  const Text hello(Colour::Green, "Hello, World!");
  con.textwriteln(hello);
  return 0;
}