# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall

# Arquivos
SRC = catch_amalgamated.cpp velha.cpp testa_velha.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = testa_velha

# Alvo padrão
all: $(EXEC)

# Linkagem final
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilação de objetos
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Executa os testes
test: $(EXEC)
	./$(EXEC)

# Valgrind
valgrind: $(EXEC)
	valgrind --leak-check=full --log-file=valgrind.rpt ./$(EXEC)

# Lint com cpplint (ignora catch)
cpplint:
	cpplint --exclude=catch_amalgamated.hpp *.cpp *.hpp

# Gcov (análise de cobertura)
gcov: clean
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c velha.cpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c testa_velha.cpp
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage catch_amalgamated.o velha.o testa_velha.o -o $(EXEC)
	./$(EXEC)
	gcov *.cpp

# Debug
debug: clean
	$(CXX) $(CXXFLAGS) -g -c catch_amalgamated.cpp
	$(CXX) $(CXXFLAGS) -g -c velha.cpp
	$(CXX) $(CXXFLAGS) -g -c testa_velha.cpp
	$(CXX) $(CXXFLAGS) -g catch_amalgamated.o velha.o testa_velha.o -o $(EXEC)
	gdb $(EXEC)

# Limpeza
clean:
	rm -f *.o *.gc* $(EXEC) valgrind.rpt *.gcov

