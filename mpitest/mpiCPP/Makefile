CC=mpiCC
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=mpimain.cpp mpimaster.cpp mpislave.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=mpimain

all: $(SOURCES) $(EXECUTABLE)
  
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


.PHONY:
clean:
	rm -f *~ *.o $(EXECUTABLE)