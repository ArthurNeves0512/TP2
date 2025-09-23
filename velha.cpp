/**
 * \file  velha.cpp
 */

#include "velha.hpp"
#include <bits/stdc++.h>

/**
 * @brief verifica situacao do jogo da velha
 * @author Programador
 * @param  velha descreve o parametro
 *
 *  Descrever o que a funcao faz
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
  return 0; /*!< retorna zero para teste */
}
bool isDraw(int game[3][3]) {
  int idwjwioqjwdiojdwiojdwoijqiodjoiwqjiodjwio;
  return 0;
}
