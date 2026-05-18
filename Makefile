CXX      = g++
CXXFLAGS = -std=c++17
SRC      = ./src/*.cpp
CREATURES = ./src/creatures/*.cpp
TARGET   = ./arena
TEST	 = ./test

build: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) $(SRC) $(CREATURES) -o $(TARGET)

test-creature: $(TEST)

$(TEST): 
	$(CXX) $(CXXFLAGS) ./src/test.cpp $(CREATURES) -o $(TEST)


TEST_SRCS = $(filter-out ./src/main.cpp, $(wildcard ./src/*.cpp))
TEST_TARGET = ./arena-test

build-test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_SRCS) $(wildcard ./src/creatures/*.cpp)
	$(CXX) $(CXXFLAGS) $(TEST_SRCS) $(CREATURES) -o $(TEST_TARGET)

clean:
	rm -f $(TARGET)
