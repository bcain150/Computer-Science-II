EXE = lab10
OBJS = IntArray.o lab10.o
CPPFLAGS = -ansi -Wall

# The variable CXX is the default C++ compiler, in this case it's g++
$(EXE): $(OBJS)
	$(CXX) $(OBJS) -o $(EXE)

.PHONY : clean
clean:
	-rm -f lab10.o $(EXE)