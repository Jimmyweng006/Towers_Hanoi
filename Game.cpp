/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve()
{
  move(stacks_[0].size(), 'A', 'B', 'C');
}
void Game::move(int n, char A, char B, char C)
{
  // Prints out the state of the game:
  // @TODO -- Finish solving the game!
  if (n == 1)
  {
    count++;
    printf("Move cube from Stack[%d] to Stack[%d]\n", A - 'A', C - 'A');
    Cube cur = stacks_[A - 'A'].removeTop();
    stacks_[C - 'A'].push_back(cur);
    cout << *this << endl;
  }
  else
  {
    move(n - 1, A, C, B);
    move(1, A, B, C);
    move(n - 1, B, A, C);
  }
}
void Game::times()
{
  cout << "Hom many times cubes move: " << count << "\n";
}
// Default constructor to create the initial state:
Game::Game(int num)
{
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++)
  {
    Stack stackOfCubes;
    stacks_.push_back(stackOfCubes);
  }

  // Create the four cubes, placing each on the [0]th stack:
  for (int i = num; i >= 1; i--)
  {
    Cube cur(i);
    stacks_[0].push_back(cur);
  }
}

std::ostream &operator<<(std::ostream &os, const Game &game)
{
  for (unsigned i = 0; i < game.stacks_.size(); i++)
  {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}
