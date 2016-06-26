CC=g++
BIN_FOLDER=./bin
SRC_FOLDER=./src
OP=-Wall -O2


build: prep kruskal_edgeList prim_adjacencyList kruskal_adjacencyList prim_fibonacci

kruskal_edgeList:
	$(CC) $(SRC_FOLDER)/kruskal_edgeList.cc -o $(BIN_FOLDER)/kruskal_edgeList $(OP)


kruskal_adjacencyList:
	$(CC) $(SRC_FOLDER)/kruskal_adjacencyList.cc -o $(BIN_FOLDER)/kruskal_adjacencyList $(OP)


prim_adjacencyList:
	$(CC) $(SRC_FOLDER)/prim_adjacencyList.cc -o $(BIN_FOLDER)/prim_adjacencyList $(OP)


prim_fibonacci:
	$(CC) $(SRC_FOLDER)/prim_fibonacci.cc -o $(BIN_FOLDER)/prim_fibonacci $(OP)


prep:
	mkdir -p $(BIN_FOLDER)

clean:
	clear
	rm -rf $(BIN_FOLDER)/*
