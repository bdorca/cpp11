SRC	=main.cpp app.cpp column.cpp
OBJ	=	$(SRC:.cpp=.o)
CPPFLAGS	=	-std=c++11 -Wall -O2
sorter.exe:	$(OBJ)
	g++ -o sorter.exe $(OBJ) -lSDL2main -lSDL2 -lSDL2_ttf
$(OBJ):

clean:
	rm -f sorter.exe $(OBJ)