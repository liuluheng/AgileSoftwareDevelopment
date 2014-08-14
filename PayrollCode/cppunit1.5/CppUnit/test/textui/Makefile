CXX = clang++
CXX = g++
CXXFLAGS = -g -Os -Wall -I../framework
#CXXFLAGS = -g -Os -Wall -stdlib=libc++ -I../framework

libtextui.a: TextTestResult.o
	ar cvr -o $@ $^

.cpp.o:
	$(CXX) -o $@ $(CXXFLAGS) -c $<

clean:
	rm -f *.o libtextui.a
