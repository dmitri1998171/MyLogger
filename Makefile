BIN := main
SRC := main.cpp
HEADER := logger.hpp
CC := g++
CFLAGS  := 
LDFLAGS :=

$(BIN): $(SRC) 
	clear && $(CC) $(SRC) -I $(HEADER) $(CFLAGS) $(LDFLAGS) -o $(BIN)

clean:
	rm -rf $(BIN)