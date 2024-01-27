#include "Player.h"

Player::Player(char sym) : symbol(sym) {}

bool Player::isAI() const { return false; }

int Player::chooseColumn(const Board &board) {
  std::string input;
  std::cout << "Player " << symbol << ", enter a column (1-" << Board::getCols()
            << ") or 0 to undo: ";
  std::cin >> input;
  int col = std::stoi(input) - 1; // Convert to 0-based index == (1-7) -> (0-6)
  return col;
}

char Player::getSymbol() const { return symbol; }
