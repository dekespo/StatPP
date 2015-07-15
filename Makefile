CC = g++ #Compiler in the system (Linux)	

IDIR = headers # directory file
CFLAGS = -std=c++11 -Wall -I $(IDIR) # Flags to be passed to compiler
LDFLAGS = -lboost_iostreams -lboost_system -lboost_filesystem -lm -lsqlite3
#Library linker (boost is for gnuplot_stream.h, lsqlite3 is for SQLite)

# object file
ODIR = obj
# source file
SDIR = src
# Select all cpp files in the soruce file
CPP_FILES = $(wildcard $(SDIR)/*.cpp)

# expected object files from each cpp file in the source file
OBJ = $(addprefix $(ODIR)/, $(notdir $(CPP_FILES:.cpp=.o)))

# creating object files
$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $< $(CFLAGS)  -o $@

# creating the executable file
bin/stat : $(OBJ)
	$(CC) $(OBJ) -o bin/stat $(LDFLAGS)

# cleaning object files and the executable file
.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(OUT) bin/*

