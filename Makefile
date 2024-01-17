CC = g++
CFLAGS = -m64 $$(pkg-config --cflags --libs Qt5Widgets qtermwidget5) -fPIC

CFILES = my-term.cpp
OBJECTS = my-term.o
DOBJECTS = dmy-term.o
BIN = my-term
DBIN = dmy-term

$(OBJECTS): %.o: src/%.cpp
	$(CC) $(CFLAGS) -o bin/$@ -c $^

$(BIN): %: %.o
	$(CC) $(CFLAGS) bin/$^ -o bin/$@

$(DOBJECTS): d%.o: src/%.cpp
	$(CC) $(CFLAGS) -g -o dbg/$@ -c $^

$(DBIN): %: %.o
	$(CC) $(CFLAGS) -g dbg/$^ -o dbg/$@
