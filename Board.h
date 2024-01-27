#ifndef BOARD_H
#define BOARD_H

#include <iostream>

// Board class
class Board {
private:
  // Using static variables because they are shared between all instances of the
  // class
  static const int ROWS = 6;
  static const int COLS = 7;
  char board[ROWS][COLS];

  /**
   * isConsecutiveFour checks if there are four consecutive pieces of the same
   * player in a row, column, or diagonal.
   *
   * @param row The row to start checking from
   * @param col The column to start checking from
   * @param rowFull The amount to increment the row by each iteration
   * @param colFull The amount to increment the column by each iteration
   * @param player The player to check for
   *
   * @return True if there are four consecutive pieces of the same player, false
   * otherwise
   */
  bool isConsecutiveFour(int row, int col, int rowFull, int colFull,
                         char player) const;

public:
  // No-arg constructor
  Board();

  // Getter
  static const int getCols();

  // Prints the board
  void printBoard() const;

  /**
   * makeMove places a piece in the specified column.
   *
   * @param col The column to place the piece in
   * @param player The player to place the piece for
   *
   * @return True if the move was successful, false otherwise
   */
  bool makeMove(int col, char player);

  /**
   * isColumnPlayable checks if the specified column is playable.
   * A column is playable if the top row is empty.
   *
   * @param col The column to check
   *
   * @return True if the column is playable, false otherwise
   */
  bool isColumnPlayable(int col) const;

  /**
   * checkWin checks if the specified player has won.
   * A player wins if they have four consecutive pieces in a row, column, or
   * diagonal.
   *
   * @param player The player to check for
   *
   * @return True if the player has won, false otherwise
   */
  bool checkWin(char player) const;

  /**
   * undoMove removes the top piece from the specified column.
   *
   * @param col The column to remove the piece from
   */
  void undoMove(int col);

  /**
   * isFull checks if the board is full.
   * The board is full if the top row of every column is not empty.
   *
   * @return True if the board is full, false otherwise
   */
  bool isFull() const;
};

#endif // BOARD_H
