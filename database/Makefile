CC=gcc
CFLAGS=-c -Wall -g
LDFLAGS=
SOURCES=database.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=test.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)
