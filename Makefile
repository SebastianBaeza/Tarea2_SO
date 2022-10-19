all:Tarea2_Main

Tarea2_Main:Tarea2_Main.c
	gcc -Wall -o Tarea2_Main.out Tarea2_Main.c && ./Tarea2_Main.out

.PHONY: clean
clean:
	rm -f *.out