CXX = g++
CXXFLAGS = -Wall

proj4: Plant.o Vegetable.o Flower.o Tree.o Fruit.o Garden.o driver.cpp driver.h
	$(CXX) $(CXXFLAGS) Plant.o Vegetable.o Flower.o Tree.o Fruit.o Garden.o driver.cpp -o proj4

Garden.o: Plant.o Vegetable.o Flower.o Tree.o Garden.cpp Garden.h
	$(CXX) $(CXXFLAGS) -c Garden.cpp

Tree.o: Plant.o Fruit.o Tree.cpp Tree.h
	$(CXX) $(CXXFLAGS) -c Tree.cpp

Flower.o: Plant.o Flower.cpp Flower.h
	$(CXX) $(CXXFLAGS) -c Flower.cpp

Vegetable.o: Plant.o Vegetable.cpp Vegetable.h
	$(CXX) $(CXXFLAGS) -c Vegetable.cpp

Fruit.o: Fruit.cpp Fruit.h
	$(CXX) $(CXXFLAGS) -c Fruit.cpp

Plant.o: Plant.cpp Plant.h
	$(CXX) $(CXXFLAGS) -c Plant.cpp

clean:
	rm *.o*
	rm *~ 

run:
	./proj4