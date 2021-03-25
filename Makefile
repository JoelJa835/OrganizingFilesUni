NAME=libauth.js
CC=gcc
LD=gcc
AR=ar
SOURCEDIR=./sources/
SOURCES=*.cc
C_SOURCES=*.c
HEADDIR=./headers/
UTIL=./util/
FUNCTION_DECLARATIONS=./headers/functions/
OBJDIR=./objects/
OBJ=*.o
SHARED=./lib/shared/
STATIC=./lib/static/
OPENSSH=./dep/openssh-portable
CC_FLAGS=-c -Wall -fpic -O2 -std=c++11 -I $(HEADDIR) -I $(UTIL) -I $(FUNCTION_DECLARATIONS)
LD_FLAGS=-lstdc++ -shared-libgcc
AR_FLAGS=rvs
SANITIZE=-fsanitize=address 
SHELL=/bin/bash
PROFILE_D=/etc/profile.d/
INCLUDE_PATH=/usr/local/include/libauthjs
SCRIPT_NAME=libauthjs.sh

build:
	@echo "##########################################################";
	@echo "Building libAuth.js library";
	@echo "##########################################################";
	@if [ -f $(OBJDIR).lock ]; then \
		echo "Removing objects from previous build"; \
		rm -f $(OBJDIR)*; \
		rm -f $(OBJDIR).lock; \
	fi
	$(CC) $(SOURCEDIR)$(SOURCES) $(CC_FLAGS);
	@mv ./*.o $(OBJDIR);
	@touch $(OBJDIR).lock;
	$(LD) $(OBJDIR)$(OBJ) $(LD_FLAGS);
	@echo "##########################################################";
	@echo "Building lib DONE!";
	@echo "Shared and static libs located under lib directory.";
	@echo "To install system-wide use 'make install' as root";
	@echo "CAUTION:This does not install the full service! This is just the lib installer!";
	@echo "To install the full service please run the install bash script located in the root dir of the project";
	@echo "##########################################################";
