CXX = g++
CXXFLAGS = -Wall

lab6: Student.o lab6.cpp
	$(CXX) $(CXXFLAGS) Student.o lab6.cpp -o lab6

Student.o: Student.cpp Student.h
	$(CXX) $(CXXFLAGS) -c Student.cpp

clean:
	rm *.o
	rm *~

run:
	./lab6
