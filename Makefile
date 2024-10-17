#make / make clean
CC = gcc
CFLAGS = -Wall -g
OBJETS = main.o wordle.o machine.o ed1.o ed2.o
TARGET = wordle

$(TARGET): $(OBJETS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJETS)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

wordle.o: wordle.c
	$(CC) $(CFLAGS) -c wordle.c

maquina.o: maquina.c
	$(CC) $(CFLAGS) -c maquina.c

ed1.o: ed1.c
	$(CC) $(CFLAGS) -c ed1.c

ed2.o: ed2.c
	$(CC) $(CFLAGS) -c ed2.c

clean:
	rm -f $(OBJETS) $(TARGET)