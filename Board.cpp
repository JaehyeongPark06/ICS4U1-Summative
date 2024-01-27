#include "Board.h"

Board::Board() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      board[i][j] = '.';
    }
  }
}

const int Board::getCols() { return COLS; }

void Board::printBoard() const {
  std::cout << std::endl;
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      std::cout << board[i][j] << " ";
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

bool Board::makeMove(int col, char player) {
  if (col < 0 || col >= COLS) {
    return false;
  }

  for (int i = ROWS - 1; i >= 0; i--) {
    if (board[i][col] == '.') {
      board[i][col] = player;
      return true;
    }
  }
  return false;
}

bool Board::isColumnPlayable(int col) const { return board[0][col] == '.'; }

bool Board::checkWin(char player) const {
  // Horizontal, Vertical, and Diagonal checks

  // Check for four consecutive pieces in a row
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col <= COLS - 4; col++) {
      if (isConsecutiveFour(row, col, 0, 1, player))
        return true;
    }
  }

  // Check for four consecutive pieces in a column
  for (int col = 0; col < COLS; col++) {
    for (int row = 0; row <= ROWS - 4; row++) {
      if (isConsecutiveFour(row, col, 1, 0, player))
        return true;
    }
  }

  // Check for four consecutive pieces in a diagonal
  for (int row = 0; row <= ROWS - 4; row++) {
    for (int col = 0; col <= COLS - 4; col++) {
      if (isConsecutiveFour(row, col, 1, 1, player))
        return true;
    }
  }

  // Check for four consecutive pieces in a diagonal (other direction)
  for (int row = 0; row <= ROWS - 4; row++) {
    for (int col = 3; col < COLS; col++) {
      if (isConsecutiveFour(row, col, 1, -1, player))
        return true;
    }
  }

  return false;
}

void Board::undoMove(int col) {
  for (int i = 0; i < ROWS; i++) {
    if (board[i][col] != '.') {
      board[i][col] = '.';
      break;
    }
  }
}

/**
 * isFull checks if the board is full.
 * The board is full if the top row of every column is not empty.
 *
 * @return True if the board is full, false otherwise
 */
bool Board::isFull() const {
  for (int col = 0; col < COLS; col++) {
    if (board[0][col] == '.') {
      return false;
    }
  }
  return true;
}

bool Board::isConsecutiveFour(int row, int col, int rowInc, int colInc,
                              char player) const {
  for (int i = 0; i < 4; i++) {
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS ||
        board[row][col] != player) {
      return false;
    }
    row += rowInc;
    col += colInc;
  }
  return true;
}
