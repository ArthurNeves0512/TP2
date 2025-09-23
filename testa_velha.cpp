
#define CATCH_CONFIG_MAIN
#include "./catch_amalgamated.hpp"
#include "./velha.hpp"
#define VENCEDOR_X 1
#define VENCEDOR_O 2
TEST_CASE("Testa velha", "[valido]") {
  int teste_X[3][3] = {{1, 1, 1}, {2, 0, 1}, {0, 2, 1}};
  int teste_0[3][3] = {{2, 2, 2}, {1, 1, 0}, {0, 0, 0}};
  REQUIRE(VerificaVelha(teste_X) == VENCEDOR_X);
  REQUIRE(VerificaVelha(teste_0) == VENCEDOR_O);
}
TEST_CASE("Testa empate", "[valido]") {
  int teste_empate[3][3] = {{1, 2, 1}, {2, 1, 2}, {1, 1, 2}};
  CHECK(isDraw(teste_empate));
}
TEST_CASE("Testa impossivel", "[invalido]") {
  int teste_impossivel[3][3] = {{1, 2, 1}, {1, 1, 2}, {1, 1, 2}};
  CHECK(isImpossible(teste_impossivel));
}
TEST_CASE("Testa ganhador", "[valido]") {
  int teste_X[3][3] = {{1, 1, 1}, {2, 0, 1}, {0, 2, 1}};
  REQUIRE(Winner(teste_X) == VENCEDOR_X);
}
TEST_CASE("Testa termino", "[valido]") {
  int game_not_ended[3][3] = {{0, 1, 1}, {2, 0, 1}, {0, 2, 1}};
  CHECK(isFinishedw(game_not_ended));
}
