#ifndef AI_H
#define AI_H

#include "Player.h"

enum Difficulty { EASY = 4, MEDIUM = 8, HARD = 10 };

class AI : public Player {
private:
  int depth;

public:
  /**
   * AI Constructor
   *
   * @param sym The symbol of the AI player
   * @param difficulty The difficulty of the AI player
   */
  AI(char sym, Difficulty difficulty);

  // Check if the player is an AI --> return false in Player class, true in AI
  // class
  bool isAI() const;

  /**
   * minimax is a recursive function that implements the minimax (search)
   * algorithm. The minimax algorithm is used to determine the best move for the
   * AI player. The algorithm is a depth-first search of the game tree.
   * Alpha-beta pruning is used to reduce the number of nodes that are
   * evaluated, shortening the time it takes to find the best move.
   *
   * @param board The board to make the move on
   * @param depth The depth of the search tree
   * @param isMaximizing True if the current player is the maximizing player,
   * false otherwise
   * @param alpha The alpha value for alpha-beta pruning
   * @param beta The beta value for alpha-beta pruning
   */
  int minimax(Board &board, int depth, bool isMaximizing, int alpha, int beta);

  // Getter for the other player's symbol
  // Used to simulate the other player's turn
  char otherPlayerSymbol() const;

  /**
   * chooseColumn prompts the AI player to choose a column
   * to place their piece in. The column is chosen using the minimax
   * algorithm.
   *
   * @param board The board to place the piece in
   *
   * @return The column to place the piece in
   */
  int chooseColumn(const Board &board);
};

#endif // AI_H
