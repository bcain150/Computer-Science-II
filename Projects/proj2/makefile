CXX = g++
CXXFLAGS = -Wall

proj2: Game.o Card.o Player.o
	$(CXX) $(CXXFLAGS) Game.o Card.o Player.o driver.cpp -o proj2

Card.o: Card.cpp Card.h
	$(CXX) $(CXXFLAGS) -c Card.cpp

Player.o: Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

Game.o: Game.cpp Game.h Card.cpp Card.h Player.cpp Player.h
	$(CXX) $(CXXFLAGS) -c Game.cpp

clean:
	rm *.o
	rm *~ 

run:
	./proj2
