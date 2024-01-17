CC = g++
CFLAGS = -m64 $$(pkg-config --cflags --libs Qt5Widgets qtermwidget5) -fPIC

CFILES = neofetchwidget.cpp
OBJECTS = neofetchwidget.o
BIN = neofetchwidget

$(OBJECTS): %.o: src/%.cpp
	$(CC) $(CFLAGS) -o bin/$@ -c $^

$(BIN): %: %.o
	$(CC) $(CFLAGS) bin/$^ -o bin/$@

$(DOBJECTS): d%.o: src/%.cpp
	$(CC) $(CFLAGS) -g -o dbg/$@ -c $^

$(DBIN): %: %.o
	$(CC) $(CFLAGS) -g dbg/$^ -o dbg/$@
