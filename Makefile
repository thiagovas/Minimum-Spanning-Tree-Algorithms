CC=g++-4.8
BIN_FOLDER=./bin
SRC_FOLDER=./src
OP=-Wall -O2


build: prep kruskal_edgeList prim_adjacencyList

kruskal_edgeList:
	$(CC) $(SRC_FOLDER)/kruskal_edgeList.cc -o $(BIN_FOLDER)/kruskal_edgeList $(OP)

prim_adjacencyList:
	$(CC) $(SRC_FOLDER)/prim_adjacencyList.cc -o $(BIN_FOLDER)/prim_adjacencyList $(OP)

prep:
	mkdir -p $(BIN_FOLDER)

clean:
	clear
	rm -rf $(BIN_FOLDER)/*
	rm -f kruskal
