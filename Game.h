/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "Stack.h"
#include <vector>

class Game
{
public:
  Game(int n);
  void solve();
  void move(int n, char A, char B, char C);
  void times();

  // An overloaded operator<<, allowing us to print the stack via `cout<<`:
  friend std::ostream &operator<<(std::ostream &os, const Game &game);

private:
  std::vector<Stack> stacks_;
  int count = 0;
};
