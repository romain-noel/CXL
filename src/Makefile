### MakeFile from Romain NOEL
##  To compile CXL 

### PATHS

## Directories 
# PROJDIR= $(realpath $(CURDIR)/..)
PROJDIR= ..
SRCDIR= $(PROJDIR)/src
SUBDIRS= LBM FDM
BUILDIR= $(PROJDIR)/build
BINDIR= $(PROJDIR)/bin
SRCSUBDIRS= $(SRCDIR) $(foreach dir, $(SUBDIRS), $(addprefix $(SRCDIR)/, $(dir)))
TARGETDIRS= $(foreach dir, $(SUBDIRS), $(addprefix $(BUILDIR)/, $(dir)))
# Generate the GCC includes parameters by adding -I before each source folder
INCLUDES= $(foreach dir, $(SOURCEDIRS), $(addprefix -I, $(dir)))
# Add this list to VPATH, the place make will look for the source files
VPATH= $(SOURCEDIRS)
# Create a list of *.c sources in DIRS
SRCFILES= $(foreach dir, $(SRCSUBDIRS), $(wildcard $(dir)/*.cpp))
OBJFILES= $(subst $(SRCDIR), $(BUILDIR), $(SRCFILES:.cpp=.o))
DEPS := $(OBJFILES:.o=.d)

## Librairies
LIBS= $(PROJDIR)/lib/rapidxml-1.13
## Includes
LIBINCLUDE= $(PROJDIR)/lib/rapidxml-1.13
INCLU=

### Compilers options
## C Gnu compiler
CC=gcc
CFLAGS=-Wall -O
## C++ Gnu Compiler
CXX=g++ -std=c++17
CXXFLAGS=-g
FASTCXXFLAGS=-DNO_DEBUG -O6 -malign-double -funroll-all-loops
LDFLAGS=
CFLAGS += -I$(LIBINCLUDE)
LDFLAGS += -L$(LIBS)
## Executable file to generate
EXEC= prog

# Decide whether the commands will be shwon or not
VERBOSE= TRUE

# Hide or not the calls depending of VERBOSE
ifeq ($(VERBOSE),TRUE)
    HIDE=  
else
    HIDE= @
endif



# This is the default target, which will be built when you invoke make
.PHONY: all
all: dir $(BUILDIR)/$(EXEC)

dir:
	@echo "[Info] Creating build directory..."
	$(HIDE)mkdir -p $(BUILDIR)
	@echo "[Info] Build successful!"


# This rule tells make how to build hello from hello.cpp
# mon_executable: exemple.o main.o ...
$(BUILDIR)/$(EXEC): $(OBJFILES) 
	$(CXX) -o $@ $^ $(LDFLAGS)
	@echo "[Info] The executable file $(BUILDIR)/$(EXEC) has been created successfully !"

# Implicit rule for all .cpp files
$(OBJFILES): $(BUILDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) -o $@ -c $< $(CFLAGS)

# This rule tells make to copy hello to the binaries subdirectory, creating it if necessary
.PHONY: install
install:
	mkdir -p $(BINDIR)
	cp -p $(BUILDIR)/$(EXEC) $(BINDIR)
	@echo "[Info] Installation completed successfully !"

# This rule tells make to delete hello and hello.o
.PHONY: clean 
clean:
	rm -f $(BUILDIR)/*o $(BUILDIR)/$(EXEC)

#
# This target makes a source distribution for shipping out to someone.
#
VERSION := 3.14

$(phony distribution):
	rm -rf combobulate-$(VERSION)	# Get rid of previous junk, if any.
	mkdir combobulate-$(VERSION)
	cp *.c *.h Makefile README INSTALL combobulate-$(VERSION)
	tar cf - combobulate-$(VERSION) | gzip -9c > combobulate-$(VERSION).tar.gz
	rm -rf combobulate-$(VERSION)

#
# This target runs regression tests to make sure the program(s) are
# doing what they are supposed to do.
#
$(phony test): $(PROGRAMS)
	noecho for testfile in *.test; do \
		./combobulate $$testfile | ./discombobulate - > junk_output; \
		if cmp -s junk_output $$testfile; then \
		echo passed $$testfile; \
		else \
		echo failed $$testfile; \
		fi; \
	done
#
# If "noecho" is the first word of the action, the action itself is not
# printed before it is executed.  In this case, printing the action
# would merely clutter up the screen so it is very common to suppress
# printing for such long commands.
#


### MEMO

# print variables
	# $(info   VAR is $(VAR))

# target: dependancies
#   commands
# internal variables:
# 	$@: name of the target 
# 	$<: name of the first dependancy
# 	$ˆ: list of dependancies
# 	$?: list of dependancies more recent than the target
# 	$*: name of a file without its suffix