#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <math.h>
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
		int elapsed = SDL_GetTicks();
		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0053)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0023)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0042)) * 128);

		for (int y = 0; y < Ekran::EKRAN_UZUNLUGU; y++){	
			for (int x = 0; x < Ekran::EKRAN_GENISLIGI; x++)
			{
				ekran.setPixel(x, y, red, green, blue);
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