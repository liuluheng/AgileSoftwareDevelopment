CXX = clang++
CXXFLAGS = -g -Os -Wall -stdlib=libc++ -std=c++11
CXXLDFLAGS = -lc++ -lc++abi

all: shape clean

shape: shape.o
	$(CXX) -o $@ $^ $(CXXLDFLAGS)

.cc.o:
	$(CXX) -o $@ $(CXXFLAGS) -c $< 

clean:
	rm -f *.o
