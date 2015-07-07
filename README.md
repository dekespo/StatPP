# Statistics in C++
A small project how statistical calculations can be done in C++ with
the help of some C++ open source libraries. All the libraries are
provided in the project.

## Included Libraries:
- **gnuplot_iostream**: www.stahlke.org/dan/gnuplot-iostream/,
 					    requires boost C++ libraries
- **boost C++**: Ubuntu download and install command line:
                 sudo apt-get install libboost-all-dev
- **sqlite3**: www.sqlite.org. sqlite3 is usually installed in Ubuntu,
			   however the library might not be installed. Ubuntu download and 
			   install command line: sudo apt-get install sqlite3 libsqlite3-dev


## How to run
Using Ubuntu terminal is suggested unless a modified way of compiling
is desired. First, run "make" in the terminal to compile and run the
executable file created in the directory bin. To clean the files, run
"make clean".

## Status
- It created data on a hard-disk and read them to plot (suitable for
  large datasets, but slow), then delete the data. It is likely to
  change in future.
- A file that provides certain distributions will be provided
- There is no GUI, it might be added in the future.
- SQLite is shown as a demo, it will be improved and be user-friendly

## Database
- test.db is provided by using the file in the following link:
  www.chinookdatabase.codeplex.com
