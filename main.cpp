/*
 * Name: Jaden Park
 * Class: ICS4U1
 * Teacher: Mr. Saleem
 * Due Date: Jan 16, 2023
 * Purpose: Connect 4 game with AI (easy, medium, hard) mode and Player vs
 * Player mode
 */
#include "Game.h"

// Menu for the game
void mainMenu() {
  std::cout << std::endl << "Welcome to Connect Four!" << std::endl;
  std::cout << "------------------------" << std::endl;
  std::cout << "Rules:" << std::endl;
  std::cout << "- The first player to get four of their pieces in a row "
               "(horizontally, vertically, or diagonally) wins."
            << std::endl;
  std::cout
      << "- Players take turns dropping pieces into a column of their choice."
      << std::endl;
  std::cout << "- Players can undo their last move by entering 0." << std::endl;
  std::cout << "- The player who goes first is chosen randomly." << std::endl;
  std::cout << "------------------------" << std::endl;
  std::cout << "Options:" << std::endl;
  std::cout << "1. Play against AI (Easy)" << std::endl;
  std::cout << "2. Play against AI (Medium)" << std::endl;
  std::cout << "3. Play against AI (Hard)" << std::endl;
  std::cout << "4. Play against another player" << std::endl;
  std::cout << "5. Exit" << std::endl;
  std::cout << "------------------------" << std::endl;
  std::cout << "Enter your choice: ";
}

int main() {
  // Hold the user's choice
  int choice;

  do {
    mainMenu();
    std::cin >> choice;

    // Check the user's choice
    switch (choice) {
    case 1: {
      Game easyGame(EASY);
      easyGame.play();
      break;
    }
    case 2: {
      Game mediumGame(MEDIUM);
      mediumGame.play();
      break;
    }
    case 3: {
      Game hardGame(HARD);
      hardGame.play();
      break;
    }
    case 4: {
      Game pvpGame('X', 'O'); // Player 1 character, Player 2 character
      pvpGame.play();
      break;
    }
    case 5:
      std::cout << std::endl << "Thank you for playing. Goodbye!" << std::endl;
      break;
    default:
      // Modifies the color of the text from white to red to white
      std::cout << "\033[0;31mInvalid choice. Try again.\033[0;37m"
                << std::endl;
    }
  } while (choice != 5);
  return 0;
}
