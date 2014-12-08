OBJS = hw6.o
EXENAME = hw6

CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi

all : $(EXENAME)

$(EXENAME) : $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

hw6.o : hw6.cpp
	$(CXX) $(CXXFLAGS) hw6.cpp
	
clean : 
	rm -f *.o $(EXENAME)
