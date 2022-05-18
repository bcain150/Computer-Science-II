CXX = g++
CXXFLAGS = -Wall

proj4: Plant.o Vegetable.o testDriver.cpp
	$(CXX) $(CXXFLAGS) Plant.o Vegetable.o testDriver.cpp -o proj4

Vegetable.o: Plant.cpp Plant.h Vegetable.cpp Vegetable.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Plant.o: Plant.cpp Plant.h
	$(CXX) $(CXXFLAGS) -c Plant.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj4