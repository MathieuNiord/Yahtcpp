G = g++
GC = ${G} -c

run: build
	./yahtzee

valgrind: build
	valgrind --leak-check=full --track-origins=yes ./yahtzee

build:
	${GC} *.cpp
	${G} -o yahtzee *.o
	
clean:
	rm -rf *.o yahtzee
	