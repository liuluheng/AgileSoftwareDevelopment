#CXX = clang++
CXX = g++
#CXXFLAGS = -g -Os -Wall -stdlib=libc++
CXXFLAGS = -g -Os -Wall

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

libframework.a: $(OBJ)
	ar cvr -o $@ $^

.cpp.o:
	$(CXX) -o $@ $(CXXFLAGS) -c $<

clean:
	rm -f *.o libframework.a
