#include "wordle.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
string guess = "", word = "";
int count = 0, k = 0;

void fillBoard(
    string board[6][5]) { // the function fillboard fills the entire board with spaces so that the whole boarclimed is still alligned even when the user hasn't inputed anything yet
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 5; j++) {
      board[i][j] = " ";
    }
  }
}

bool checkword(string board[6][5], string guess, string word,
                int amount_of_guesses) {
  string coloredLetter = "";
  bool isequal=true;
  for (int i = 0; i < 5; i++) { // this forloop checks the guess word
    if (toupper(guess[i]) ==
        toupper(word[i])) { // if the letter is in the word and in the correct
                            // spot it will be green
      coloredLetter = string("\x1b[32m") + char(guess[i]-32) + string("\x1b[0m");

    } else { // if the letter is not green then this next for loop checks for yellow letters
      isequal=false;
      for (int k = 0; k < 5; k++) { // it checks each spot in the word to see if
                                    // the letter is in the word
        if (toupper(guess[i]) == toupper(word[k])) {
          coloredLetter = string("\x1b[33m") + char(guess[i]-32) + string("\x1b[0m");
          k = 0;
          break;
        } else {
          if (k == 4) { // if it's not in the word than the letter doesn't have
                        // a color
            coloredLetter = + char(guess[i]-32);
          }
        }
      }
    }
    board[amount_of_guesses][i] = coloredLetter;
  }
  return isequal;
}

string chooseword(){//this function reads from a textfile and inputs each line as a string in an array of strings. Than using the rand function ends up chosing a random string from the array
  string wordbank[1000];
  string inputword;
  int linenumber=0;
  ifstream MyReadFile("wordbank.txt");
  while (getline (MyReadFile, inputword)) {
    wordbank[linenumber]=inputword;
    linenumber++;
  }
  srand(time(0));
  int chosenbooknumber=rand() % linenumber;
  MyReadFile.close();

  return wordbank[chosenbooknumber];
}


void drawBoard(string board[6][5]) { // funtion to create the board
  cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << " | "
       << board[0][3] << " | " << board[0][4] << endl;
  cout << "-----------------" << endl;
  cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << " | "
       << board[1][3] << " | " << board[1][4] << endl;
  cout << "-----------------" << endl;
  cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << " | "
       << board[2][3] << " | " << board[2][4] << endl;
  cout << "-----------------" << endl;
  cout << board[3][0] << " | " << board[3][1] << " | " << board[3][2] << " | "
       << board[3][3] << " | " << board[3][4] << endl;
  cout << "-----------------" << endl;
  cout << board[4][0] << " | " << board[4][1] << " | " << board[4][2] << " | "
       << board[4][3] << " | " << board[4][4] << endl;
  cout << "-----------------" << endl;
  cout << board[5][0] << " | " << board[5][1] << " | " << board[5][2] << " | "
       << board[5][3] << " | " << board[5][4] << endl;
}