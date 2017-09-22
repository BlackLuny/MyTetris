Tetris:TetrisBase.o Point.o main.o Tetris.o GameFram.o TetrisLine.o TetrisSquare.o AggregateBase.o KeyDownHandler.o CommonFunc.o
	g++ -o Tetris Tetris.o Point.o main.o TetrisBase.o TetrisLine.o TetrisSquare.o GameFram.o AggregateBase.o KeyDownHandler.o CommonFunc.o
Tetris.o: Point.h Point.cpp vel.h TetrisBase.h Product.h Tetris.cpp Tetris.h IteratorBase.h AggregateBase.h TetrisMap.h TetrisMapIterator.h TetrisLine.cpp TetrisSquare.cpp GameFram.cpp AggregateBase.cpp KeyDownHandler.cpp CommonFunc.cpp
	g++ -c Point.cpp TetrisBase.cpp Tetris.cpp TetrisLine.cpp TetrisSquare.cpp GameFram.cpp AggregateBase.cpp KeyDownHandler.cpp CommonFunc.cpp
main.o: main.cpp Tetris.h
	g++ -c Tetris.cpp main.cpp

Clean:
	rm -f *.o