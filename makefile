#--------------------------------------------------------------------
# author:       cutcprog
# version:      12.08.26
# Generic make file for Project Euler.
#--------------------------------------------------------------------

FIRSTNAME       =       Andrea
LASTNAME        =       Grooms

LAB             =       7
SOURCES         =       main.cpp QuestionTree.cpp
OBJECTS         =       $(SOURCES:.cpp=.o)
EXECUTABLE      =       main.exe
OTHER	        =       makefile  $(SOURCES:.cpp=.h)

# I am assumming g++, zip, rm, ollydbg are set up in a path
GCC         =   g++
LINK        =   g++
ZIP         =   zip
RM          =   rm
#DEBUG       =   ollydbg.exe
CFLAGS      =   -c 

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(GCC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(GCC) $(CFLAGS) $< -o $@

clean:
	$(RM)   \*.exe \*.o

zip:    $(SOURCES)
	$(ZIP) Lab$(LAB)_$(FIRSTNAME)_$(LASTNAME).zip $(SOURCES) $(OTHER) 
