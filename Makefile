all:tarea_2

tarea_2:tarea_2.c
	gcc -Wall -o tarea_2.out tarea_2.c && ./tarea_2.out

.PHONY: clean
clean:
	rm -f *.out