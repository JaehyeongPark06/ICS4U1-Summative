#include "Game.h"
#include <cstdlib>
#include <ctime>

Game::Game(Difficulty difficulty) : player1('X'), player2('O'), isPvP(false) {
  // Set the AI player
  aiPlayer = new AI('O', difficulty);

  std::srand(std::time(
      nullptr)); // Get new seed for RNG to randomly decide who goes first

  // Randomly decide who goes first
  currentPlayer = (std::rand() % 2 == 0) ? &player1 : aiPlayer;

  // Output the starting player and board
  std::cout << "Starting player: Player " << currentPlayer->getSymbol()
            << std::endl;
  board.printBoard();
}

Game::Game(char player1Symbol, char player2Symbol)
    : player1(player1Symbol), player2(player2Symbol), isPvP(true) {
  aiPlayer = nullptr; // No AI player in PvP mode
  std::srand(std::time(
      nullptr)); // Get new seed for RNG to randomly decide who goes first

  // Randomly decide who goes first
  currentPlayer = (std::rand() % 2 == 0) ? &player1 : &player2;

  // Output the starting player and board
  std::cout << "Starting player: Player " << currentPlayer->getSymbol()
            << std::endl;
  board.printBoard();
}

void Game::switchPlayer() {
  // Checks the gamemode
  if (isPvP) {
    currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
  } else {
    currentPlayer = (currentPlayer == &player1) ? aiPlayer : &player1;
  }
}

void Game::play() {
  bool gameRunning = true;
  std::stack<int> moveHistory; // Stack to track move history for undo

  while (gameRunning) {
    // Output who's turn it is
    std::cout << "Current turn: Player " << currentPlayer->getSymbol()
              << std::endl;

    // Check if the current player is an AI
    // If so, output that the AI is thinking
    if (!isPvP && currentPlayer == aiPlayer) {
      std::cout << "AI is thinking..." << std::endl;
    }

    // Get the column to place the piece in
    int col = currentPlayer->chooseColumn(board);

    // We check if it's -1 and not 0 because we subtract 1 from the user's
    // input to convert it to 0-based index (1-7) -> (0-6)
    if (col == -1) {
      // Undo move if there are at least two moves to undo
      if (moveHistory.size() >= 2) {
        // Ensure there are at least two moves to undo
        // Undo last move of the current player
        int lastCol = moveHistory.top();
        moveHistory.pop();
        board.undoMove(lastCol);

        // Undo last move of the other player
        lastCol = moveHistory.top();
        moveHistory.pop();
        board.undoMove(lastCol);

        std::cout << "Moves undone. Current board:" << std::endl;
        board.printBoard();
      } else {
        // Modifies the color of the text from white to red to white
        std::cout << "\033[0;31mNot enough moves to undo.\033[0;37m"
                  << std::endl;
      }
    }

    // Check if the move is valid
    else if (board.makeMove(col, currentPlayer->getSymbol())) {
      // Record the move in the move history
      moveHistory.push(col);

      // Output the board after the move
      std::cout << std::endl
                << "Board after Player " << currentPlayer->getSymbol()
                << "'s move:" << std::endl;
      board.printBoard();

      // If the current player has won
      if (board.checkWin(currentPlayer->getSymbol())) {
        std::cout << "Player " << currentPlayer->getSymbol() << " wins!"
                  << std::endl;
        gameRunning = false; // End the game
      }

      // Check if the board is full (draw)
      else if (board.isFull()) {
        std::cout << "The board is full. It's a draw!" << std::endl;
        gameRunning = false; // End the game
      }

      // If the game's not over, switch the player
      else {
        switchPlayer();
      }
    } else {
      // Modifies the color of the text from white to red to white
      std::cout << "\033[0;31mInvalid move. Try again.\033[0;37m" << std::endl;
      board.printBoard();
    }
  }
}
