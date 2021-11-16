CC = g++
CFLAGS = -std=c++11
OBJS = sort.o search.o main.o
TARGET = runnable

all: cc/sort cc/search cc/main link run ## compile and run

cc/sort: sort.cpp ## compile sort library
	$(CC) $(CFLAGS) -o sort.o -c sort.cpp

cc/search: search.cpp ## compile search library
	$(CC) $(CFLAGS) -o search.o -c search.cpp

cc/main: main.cpp ## compile main
	$(CC) $(CFLAGS) -o main.o -c main.cpp

link: $(OBJS) ## link binary files
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

run: $(TARGET) ## run
	./$(TARGET)

clean: ## remove binary files
	rm -rf $(OBJS) $(TARGET)

help: ## display this help screen
	@grep -E '^[a-zA-Z/_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-20s\033[0m %s\n", $$1, $$2}'
