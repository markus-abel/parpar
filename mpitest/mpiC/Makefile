CC=mpicc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=mpimain.c mpimaster.c mpislave.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=mpimain

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@


.PHONY:
clean:
	rm -f *~ *.o $(EXECUTABLE)