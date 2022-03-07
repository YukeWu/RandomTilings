# Makefile
# Requires that the object definitions be in tilings.h and tilings.cpp

CXX = g++
CXXFLAGS =  -O2 -g -Wall

# During debugging you may want to used the compiler flags listed below
#CXXFLAGS =      -g -Wall

all: tilings

tilings: tilings.cpp
	$(CXX) $(CXXFLAGS) tilings.cpp -o $@

clean:
	rm -f core *.o tilings

