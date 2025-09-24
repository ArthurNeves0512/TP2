/**
 * \file  game.cpp
 */

#include "velha.hpp"
#include <bits/stdc++.h>
#define IS_X 1
#define IS_O 2
#define CAN_PLACE_MARK 0
/**
 * @brief verifica situacao do jogo da game
 * @author Arthur Neves
 * @param  game Is the game grid
 *
 *  Check all condictions and return the actual status of the board
 */
using namespace std;
int GameVerify(int game[3][3]) {
  if (IsImpossible(game)) {
    return -2;
  }
  if (!IsFinishedw(game)) {
    return -1;
  }
  if (IsDraw(game)) {
    return 0;
  }
  return Winner(game);
}
bool IsDraw(int game[3][3]) { return Winner(game) == 0 ? true : false; }
bool IsImpossible(int game[3][3]) {
  int countX = 0;
  int countO = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (game[i][j] == IS_X) {
        countX += 1;
      } else if (game[i][j] == IS_O) {
        countO += 1;
      }
    }
  }
  return abs(countO - countX) > 1 ? true : false;
}

bool IsFinishedw(int game[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (game[i][j] == CAN_PLACE_MARK) {
        return true;
      }
    }
  }
  return false;
}
int Winner(int game[3][3]) {

  for (int i = 0; i < 3; i++) {
    bool horizontal_match =
        game[i][0] == game[i][1] && game[i][0] == game[i][2];
    bool vertical_match = game[0][i] == game[1][i] && game[0][i] == game[2][i];
    if (horizontal_match || vertical_match) {
      return game[i][0];
    }
  }
  if ((game[0][0] == game[1][1] && game[1][1] == game[2][2]) ||
      (game[2][2] == game[0][2] && game[2][2] == game[1][1])) {
    return game[1][1];
  }
  return 0;
}
