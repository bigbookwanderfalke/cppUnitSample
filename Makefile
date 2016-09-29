CC=g++
SRC=Class1.cpp
all:SRC+=Class1_exec.cpp
all:EXE=run.exe
test:SRC+=Class1_test.cpp
test:EXE=test.exe
LIB=
test:LIB+=-lcppunit
clean:EXE=run.exe test.exe

all:
	$(CC) -o $(EXE) $(SRC) $(LIB)

test:
	$(CC) -o $(EXE) $(SRC) $(LIB)

clean:
	-rm $(EXE)
