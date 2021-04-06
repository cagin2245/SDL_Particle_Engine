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
		for (int y = 0; y < Ekran::EKRAN_UZUNLUGU; y++){	
			for (int x = 0; x < Ekran::EKRAN_GENISLIGI; x++)
			{
				ekran.setPixel(x, y, 128, 0, 255);
			}
		}
		 
		// Check for messages/events
		ekran.setPixel(400, 300, 255, 255, 255);
		ekran.update();// Draw the screen


		if (ekran.processEvents() == false)
		{
			break;
		}		
	}

	cout << "SDL Init succeeded." << endl;
	

		return 0;
}