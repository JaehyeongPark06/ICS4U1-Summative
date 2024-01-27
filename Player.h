#ifndef PLAYER_H
#define PLAYER_H

#include "Board.h"
#include <iostream>

class Player {
protected:
  char symbol;

public:
  /**
   * Player Constructor
   *
   * @param sym The symbol of the player
   */
  Player(char sym);

  // Check if the player is an AI --> return false in Player class, true in AI
  // class
  virtual bool isAI() const;

  /**
   * chooseColumn prompts the player to choose a column to place their piece in.
   *
   * @param board The board to place the piece in
   *
   * @return The column to place the piece in
   */
  virtual int chooseColumn(const Board &board);

  // Getter
  char getSymbol() const;
};

#endif // PLAYER_H
