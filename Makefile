CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: lab10

lab10: lab10.cpp
	$(CXX) $(CXXFLAGS) lab10.cpp -o lab10

run: lab10
	./lab10

clean:
	rm -f lab10