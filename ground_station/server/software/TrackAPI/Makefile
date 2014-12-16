TRACKER_DIR = SCTracker
TARGET = server
LIB = $(TRACKER_DIR)/libsctracker.a

all: $(TARGET)

$(TARGET) : $(LIB) server.go tracker.go
	go build -o $(TARGET) server.go tracker.go

$(LIB) :
	git submodule init
	git submodule update
	cp Makefile.lib c.h c.cpp $(TRACKER_DIR)
	cd $(TRACKER_DIR) && $(MAKE) -f Makefile.lib

clean :
	@rm -f $(TARGET)
	cd $(TRACKER_DIR) && $(MAKE) -f Makefile.lib clean
