// Semi Kim
// ITP 165, 2024 spring
// Homework 08 TicTacToe

#include <iostream>

// Function: makeBoard
// Purpose: Dynamically create a 9-item char array and initialize each item
// Parameters: None
// Returns: char pointer to the array
char* makeBoard()
{
  char* board = new char[9];
  for (int i = 0; i < 9; i++)
    {
      board[i] = '1' + i;
    }
  return board;
}

// Function: displayBoard
// Purpose: Display a tic-tac-toe board
// Parameters: const char pointer to the array
// Returns: Nothing
void displayBoard(const char* board)
{
  for (int i = 0; i < 9; i++)
  {
    std::cout << " " << board[i];
    if ((i + 1) % 3 == 0 && i != 8)
    {
      std::cout << "\n------------\n";
    }
    else
    {
      if (i != 8)
      {
        std::cout << " |";
      }
    }
  }
}

// Function: validMove
// Purpose: Check if a move is valid (in range; isn't already claimed)
// Parameters: const char pointer to the array, int representing target board position claimed by player
// Returns: true if the “target” board position can be claimed and false if it cannot.
bool validMove(const char* board, int target)
{
  // Check if the target is in range
  if (target < 1 || target > 9)
  {
    return false;
  }
  
  // Check if the target is already claimed
  if (board[target-1] == 'X' || board[target-1] == 'O')
  {
    return false;
  }
  
  return true;
}

// Function: determineWinner
// Purpose: Determine if there is a winner
// Parameters: const char pointer to the array
// Returns: a single char representing the winner (X, O, or N)
char determineWinner(const char* board) {
  // Check rows
  for (int i = 0; i < 3; i++) {
      if (board[i * 3] == board[i * 3 + 1] && board[i * 3 + 1] == board[i * 3 + 2])
      {
        return board[i * 3];
      }
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
      if (board[i] == board[i + 3] && board[i + 3] == board[i + 6])
      {
        return board[i];
      }
  }

  // Check diagonals
  if ((board[0] == board[4] && board[4] == board[8]) || (board[2] == board[4] && board[4] == board[6]))
  {
    return board[4];
  }

  // No winner
  return 'N';
}

// Function: fullBoard
// Purpose: Check if the board is full
// Parameters: const char pointer to the array
// Returns: true if the board is full and false if it is not
bool fullBoard(const char* board) {
  for (int i = 0; i < 9; i++) {
      if (board[i] != 'X' && board[i] != 'O')
      {
        return false;
      }
    }
    return true;
}

int main()
{
  std::cout << "Let’s start a game!\n";
  // Initialize the board
  char* board = makeBoard();
  char winner = determineWinner(board);
  bool full = fullBoard(board);

  // Initialize variables
  int turn = 0;
  std::string playAgain = "y";
  winner = 'N';

  while (playAgain == "y" && winner == 'N') {
    std::cout << "\nHere is a current board...\n";
    displayBoard(board);
    
    if (turn % 2 == 0)
    {
      std::cout << "\nIt's X's turn!";
    }
    else
    {
      std::cout << "\nIt's O's turn!";
    }
    
    int target;
    std::cout << "\nWhere do you want to go? ";
    std::cin >> target;
    
    // Check if the move is valid
    bool valid = validMove(board, target);
    validMove(board, target);
    while (!valid)
      {
        std::cout << "\t\tINVALID OPTION. Pick again.";
        std::cout << "\nHere is the current board...\n";
        displayBoard(board);
        std::cout << "\nWhere do you wanna go? ";
        std::cin >> target;
        valid = validMove(board, target);
      }

    // Update the board
    turn++;  // Increment the turn counter
    if (turn % 2 == 0)
    {
      board[target-1] = 'O';
    }
    else
    {
      board[target-1] = 'X';
    }

    // Check if there is a winner
    winner = determineWinner(board);
    full = fullBoard(board);

    // Check if the game is over
    if (winner != 'N')  // if there is a winner (X or O)
    {
      // Display the winner
      std::cout << "\n!!! " << winner << " WINS !!!\n";

      // Ask if player wants to play again
      std::cout << "Wanna play again (y/n)? ";
      std::cin >> playAgain;
      while (playAgain != "y" && playAgain != "n")
      {
        std::cout << "\t\tINVALID OPTION. Try again...";
        std::cout << "\nWanna play again (y/n)? ";
        std::cin >> playAgain;
      }
      
      // Reset the board, turn, and winner
      delete[] board;
      board = makeBoard();
      turn = 0;
      winner = 'N';
    }
    else  // if there is no winner (yet)
    {
      if (full)  // if the board is full
      {
        // Display the winner
        std::cout << "\n!!! STALEMATE !!!\n";

        // Ask if player wants to play again
        std::cout << "Wanna play again (y/n)? ";
        std::cin >> playAgain;
        while (playAgain != "y" && playAgain != "n")
        {
          std::cout << "\t\tINVALID OPTION. Try again...";
          std::cout << "\nWanna play again (y/n)? ";
          std::cin >> playAgain;
        }
        
        // Reset the board, turn, and winner
        delete[] board;
        board = makeBoard();
        turn = 0;
        winner = 'N';
      }
    }
  }
std::cout << "See ya!";
}

