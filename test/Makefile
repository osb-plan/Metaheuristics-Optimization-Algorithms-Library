# Compiler and Linker
CC=g++

include config.mk

# Settings from .mk
ifeq ($(DEBUG),y)
	EXT_FLAGS=-g
else
	EXT_FLAGS=
endif

# Target Binary
TARGET=oal_example

INSTALL_DIR=dist
# Flags
CFLAGS=-c -Wall $(EXT_FLAGS) -O0
LDFLAGS=-lm -loal

# Include, Source and Libs
INCDIR=-I./include -I../
LIBDIR=-L../
SRCDIR=./src/
SOURCES=$(SRCDIR)main.cpp
OBJECTS=$(SOURCES:.cpp=.o)

EXECUTABLE=oal_example
ifeq ($(DBG_PRINT),y)
   DBG_PRINT_FLAG=-D DBG_PRINT
endif

all: $(SOURCES) $(EXECUTABLE)
	    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LIBDIR) $(LDFLAGS)

.cpp.o:
	$(CC) $(DBG_PRINT_FLAG) $(CFLAGS) $(INCDIR) $< -o $@

.PHONY: clean install all 

clean:
ifeq (,$(wildcard ./$(TARGET)))
	@rm $(SRCDIR)*.o; rm -rf $(INSTALL_DIR)
else
	@rm $(SRCDIR)*.o $(TARGET); rm -rf $(INSTALL_DIR)
endif

install:
	@mkdir $(INSTALL_DIR); mv $(TARGET) $(INSTALL_DIR)
	
