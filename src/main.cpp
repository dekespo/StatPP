#include "general.h" 

int main()
{
	// Write the initial text
	starting(); // text.cpp

	bool programRunCheck = true;

	srand(time(NULL));

	// Run the program until the user exits
	while(programRunCheck)
	{
		// Choose option
		int init = instructions(); //text.cpp
		
		switch(init)
		{
			// Functions are in case_functions.cpp

			// Manual Data adding
			case 1: { manualDataAdd(); break; }
			// RandomGenerator	
			case 2: { randomGeneratorAdd(); break; }
			// SQLite Demo (will change in future)
			case 3: { SQLiteAdd(); break; }
			// Exit
			case 4: { programRunCheck = false; break;}
			// Testing Case
			case 9: { testingAdd(); break; }
			// False enter
			default: std::cout << "You entered an invalid option" << std::endl;
		}
	}	

	// Finisihing the program
	terminating(); //text.cpp 

	return 0; // Finish the program sucessfully
}
