#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include "Ekran.h"
#undef main

using namespace std;
using namespace cagin2245;

int main() 
{
	Ekran ekran;
	if (ekran.init() == false)
	{
		cout << "Error initialising SDL." << endl;
	}
	


	bool quit = false;
	
	while (true) // Game Loop
	{	// Update Particles
		// Draw Particles
		// Check for messages/events
		if (ekran.processEvents() == false)
		{
			break;
		}		
	}

	cout << "SDL Init succeeded." << endl;
	

		return 0;
}