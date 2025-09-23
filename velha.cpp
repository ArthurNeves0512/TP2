/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include <bits/stdc++.h>
#define IS_X 1
#define IS_O 2
#define CAN_PLACE_MARK 0
/**
 * @brief verifica situacao do jogo da velha
 * @author Arthur Neves
 * @param  game is the game grid
 *
 *  Check all condictions and return the actual status of the board
 */
using namespace std;
int VerificaVelha(int velha[3][3]) {
  for (int i = 0; i < 3; i++) {
    bool horizontal_match =
        velha[i][0] == velha[i][1] && velha[i][0] == velha[i][2];
    bool vertical_match =
        velha[0][i] == velha[1][i] && velha[0][i] == velha[2][i];
    if (horizontal_match || vertical_match) {
      return velha[i][0];
    }
  }
  if ((velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) ||
      (velha[2][2] == velha[0][2] && velha[2][2] == velha[1][1])) {
    return velha[1][1];
  }
  return 0;
}
bool isDraw(int game[3][3]) { return VerificaVelha(game) == 0 ? true : false; }
bool isImpossible(int game[3][3]) {
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
  return abs(countO - countX) <= 1 ? true : false;
}

bool isFinishedw(int game[3][3]) {

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (game[i][j] == CAN_PLACE_MARK) {
        return true;
      }
    }
  }
  return false;
}
int Winner(int velha[3][3]) {

  for (int i = 0; i < 3; i++) {
    bool horizontal_match =
        velha[i][0] == velha[i][1] && velha[i][0] == velha[i][2];
    bool vertical_match =
        velha[0][i] == velha[1][i] && velha[0][i] == velha[2][i];
    if (horizontal_match || vertical_match) {
      return velha[i][0];
    }
  }
  if ((velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) ||
      (velha[2][2] == velha[0][2] && velha[2][2] == velha[1][1])) {
    return velha[1][1];
  }
  return 0;
}
