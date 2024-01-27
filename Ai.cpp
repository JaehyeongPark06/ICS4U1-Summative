#include "Ai.h"
#include <ctime>

AI::AI(char sym, Difficulty difficulty) : Player(sym) {
  std::srand(std::time(NULL));
  switch (difficulty) {
  case EASY:
    depth = EASY;
    break;
  case MEDIUM:
    depth = MEDIUM;
    break;
  case HARD:
    depth = HARD;
    break;
  }
}

bool AI::isAI() const { return true; }

int AI::minimax(Board &board, int depth, bool isMaximizing, int alpha,
                int beta) {
  // Base cases
  // Check if the current player has won
  if (board.checkWin(this->symbol)) {
    return 10;
  }

  // Check if the other player has won
  else if (board.checkWin(otherPlayerSymbol())) {
    return -10;
  }

  // Check if the board is full (draw)
  else if (depth == 0 || board.isFull()) {
    return 0;
  }

  // Recursive cases
  // Maximizing player
  if (isMaximizing) {
    // Find the best score
    // Set to a very low value so that the first score will always be higher
    int bestScore = -1000000;

    // Loop through each column
    for (int col = 0; col < board.getCols(); col++) {
      // Check if the column is playable (not full)
      if (board.isColumnPlayable(col)) {
        // Make a move in the column
        board.makeMove(col, this->symbol);

        // Recursively call minimax with the new board state
        // Lower the depth by 1 to simulate the next player's turn
        int score = minimax(board, depth - 1, false, alpha, beta);

        // Undo the move
        board.undoMove(col);

        // Update the best score
        bestScore = std::max(bestScore, score);

        // Update alpha
        alpha = std::max(alpha, bestScore);

        // Alpha-beta pruning
        if (beta <= alpha) {
          break; // Beta cut-off
        }
      }
    }
    return bestScore;
  } else {
    // Repeat the same process for the minimizing player
    int bestScore = 1000000;
    for (int col = 0; col < board.getCols(); col++) {
      if (board.isColumnPlayable(col)) {
        // Make a move in the column
        board.makeMove(col, otherPlayerSymbol());

        // Recursively call minimax with the new board state
        int score = minimax(board, depth - 1, true, alpha, beta);

        // Undo the move
        board.undoMove(col);

        // Update the best score
        bestScore = std::min(bestScore, score);

        // Update beta
        beta = std::min(beta, bestScore);

        // Alpha-beta pruning
        if (beta <= alpha) {
          break; // Alpha cut-off
        }
      }
    }
    return bestScore;
  }
}

char AI::otherPlayerSymbol() const { return (this->symbol == 'X') ? 'O' : 'X'; }

int AI::chooseColumn(const Board &board) {
  int bestScore = -1000000;
  int bestMove = 0;
  int alpha = -1000000;
  int beta = 1000000;

  for (int col = 0; col < Board::getCols(); col++) {
    // Check if the column is playable (not full)
    if (board.isColumnPlayable(col)) {
      // Create a new board
      Board mutableBoard = board;
      // Make a move in the column
      mutableBoard.makeMove(col, this->symbol);

      int score = minimax(mutableBoard, depth, false, alpha, beta);

      if (score > bestScore) {
        // Update the best score and move
        bestScore = score;
        bestMove = col;
        alpha = std::max(alpha, score);
      }
    }
  }
  return bestMove;
}
