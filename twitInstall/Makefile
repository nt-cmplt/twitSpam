# Hey Emacs, this is a -*- makefile -*-
# The twitcurl library.. a Makefile for OpenWRT
# Makefile-fu by John Boiles
# 28 September 2009

LIBNAME = twitcurl
SRC = *.cpp
STAGING_DIR = 
INCLUDE_DIR = $(STAGING_DIR)/usr/include
LIBRARY_DIR = $(STAGING_DIR)/usr/lib
LDFLAGS += -Wl,-rpath-link=$(STAGING_DIR)/usr/lib
CC = g++
REMOVE = rm -f
COPY = cp
REMOTEIP = 192.168.1.30

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
# CSTANDARD = -std=gnu99

# Place -D or -U options here
CDEFS =

# Place -I options here
CINCS = 

CFLAGS =$(CDEFS) $(CINCS) $(CSTANDARD)

all: target

target: $(SRC) $(LIBNAME).h
	$(CC) -Wall -fPIC -c -include stdlib.h -I$(INCLUDE_DIR) $(SRC)
	$(CC) -shared -Wl,-soname,lib$(LIBNAME).so.1 $(LDFLAGS) -L$(LIBRARY_DIR) -lcurl -o lib$(LIBNAME).so.1.0 *.o

#clean project.
clean:
	$(REMOVE) $(LIBNAME)*.so.1.0
	$(REMOVE) $(LIBNAME).o
	$(REMOVE) $(LIBRARY_DIR)/lib$(LIBNAME).so*
	
# Install library to local openwrt library directory
install: all
	$(COPY) lib$(LIBNAME).so.1.0 $(LIBRARY_DIR)
	$(COPY) *.h $(INCLUDE_DIR)/
	ln -sf $(LIBRARY_DIR)/lib$(LIBNAME).so.1.0 $(LIBRARY_DIR)/lib$(LIBNAME).so
	ln -sf $(LIBRARY_DIR)/lib$(LIBNAME).so.1.0 $(LIBRARY_DIR)/lib$(LIBNAME).so.1
