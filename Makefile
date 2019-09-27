# Compiler and Linker
CC=g++

include config.mk

$(info "STATIC FLAG =" [${STATIC_LIB_BUILD}])
$(info "DEBUG FLAG ="  [${DEBUG}])
$(info "DEBUG PRINT ="  [${DBG_PRINT}])


EXT_FLAGS=

# Settings from .mk
ifeq ($(DEBUG),y)
	EXT_FLAGS=-g 
endif

# Target Binary

EXECUTABLE=oal_start

INSTALL_DIR=bin
INSTALL_LIB_DIR=libs
SHARED_LIB=liboal.so
STATIC_LIB=liboal.a

# Flags
CCFLAGS= -std=c++11  -Wall -Wextra $(EXT_FLAGS)
LDFLAGS=-lm

# Include, Source and Libs
INCDIR=-I./include
LIBDIR=
SRCDIR=./src/
SOURCES=$(SRCDIR)*.cpp
OBJECTS=$(SOURCES:.c=.o)

ifeq ($(DBG_PRINT),y)
	DBG_PRINT_FLAG=-D DBG_PRINT
endif

ifeq ($(STATIC_LIB_BUILD),y)
	TARGET=$(SOURCES) $(STATIC_LIB)
else
	TARGET=$(SOURCES) $(SHARED_LIB)
endif

#ifeq ($(ARCH),64)
	#_ARCH=-D_ARCH_INT=uint64_t
#endif

#ifeq ($(ARCH),32)
#    _ARCH=-D_ARCH_INT=uint32_t
#endif

#ifeq ($(ARCH),float)
#	_ARCH=-D_ARCH_INT=float
#endif
#$(info "ARCH =" [${ARCH}])

all: $(TARGET)

$(STATIC_LIB):
	ar -rcsv $(STATIC_LIB) $^
	@echo	 "Creating Static OAL Lib"
	ranlib $(STATIC_LIB)

$(SHARED_LIB): $(OBJECTS)
	@echo "Creating Dynamic OAL Lib"
	$(CC) $(DBG_PRINT_FLAG) -shared -fPIC -o $@ $(OBJECTS) $(CCFLAGS) $(_ARCH) 

.cpp.o:
	$(CC) $(DBG_PRINT_FLAG) $(CCFLAGS) $(INCDIR) $< -o $@

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS) 

.PHONY: clean install all 

clean:
	
ifneq ("$(wildcard $(STATIC_LIB))","")
	@echo "Removing static lib"
	@rm $(STATIC_LIB);
endif

ifneq ("$(wildcard $(SHARED_LIB))","")
	@echo "Removing shared lib"
	@rm $(SHARED_LIB);rm ./src/*.o
endif

ifneq ("$(wildcard $(INSTALL_LIB_DIR))","")
	@echo "Removing installation folder"
	@rm -rf $(INSTALL_LIB_DIR)
endif

install:
	@echo "Install libs on libs/ folder"	
ifneq ("$(wildcard $(STATIC_LIB))","")
	@mkdir $(INSTALL_LIB_DIR); mv $(STATIC_LIB) $(INSTALL_LIB_DIR)
else
	@mkdir $(INSTALL_LIB_DIR); mv $(SHARED_LIB) $(INSTALL_LIB_DIR)
endif	
