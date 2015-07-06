CC = g++ #Compiler in the system (Linux)	

IDIR = headers # directory file
CFLAGS = -std=c++11 -Wall -I $(IDIR) # Flags to be passed to compiler
LDFLAGS = -lboost_iostreams -lboost_system -lboost_filesystem -lm -lsqlite3
#Library linker (boost is for gnuplot_stream.h, lsqlite3 is for SQLite)

# object file
ODIR = obj
# source file
SDIR = src

OBJ = $(addprefix $(ODIR)/, SQLite.o plotGNU.o data_group.o text.o statistical_methods.o random_generator.o main.o) #expected object files

#creating object files
$(ODIR)/%.o: $(SDIR)/%.cpp
	$(CC) -c $< $(CFLAGS)  -o $@

#creating the executable file
bin/stat : $(OBJ)
	$(CC) $(OBJ) -o bin/stat $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(ODIR)/*.o $(OUT) bin/*

