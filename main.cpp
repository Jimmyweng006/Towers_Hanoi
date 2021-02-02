/**
 * Simple main to create and solve a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include <iostream>

int main()
{
  int num_cube;
  std::cout << "How many cube you want to play: ";
  std::cin >> num_cube;
  Game g(num_cube);

  std::cout << "Initial game state: " << std::endl;
  std::cout << g << std::endl;

  g.solve();
  g.times();

  std::cout << "Final game state: " << std::endl;
  std::cout << g << std::endl;

  return 0;
}