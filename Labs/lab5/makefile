CXX = g++
CXXFLAGS = -Wall

lab5: File.o
	$(CXX) $(CXXFLAGS) File.o lab5.cpp -o lab5

File.o: File.cpp File.h
	$(CXX) $(CXXFLAGS) -c File.cpp
