#ifndef GAME_H
#define GAME_H

#include "Ai.h"
#include "Board.h"
#include "Player.h"
#include <stack>

class Game {
private:
  Board board;
  Player player1;
  Player player2;
  AI *aiPlayer; // Pointer to AI player --> using a pointer allows us to use
  // polymorphism to switch between Player and AI
  // also no memory allocated unless its AI vs player mode
  Player *currentPlayer; // Same goes for current player
  bool isPvP;

public:
  // Player vs AI Constructor
  Game(Difficulty difficulty);

  // Player vs Player Constructor
  Game(char player1Symbol, char player2Symbol);

  // Switch the current player
  void switchPlayer();

  // Play the game (loop)
  void play();
};

#endif // GAME_H
