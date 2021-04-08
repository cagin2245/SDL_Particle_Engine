#include <iostream>
#include <stdio.h>
#include <SDL.h>
#include <math.h>
#include "Ekran.h"
#include <time.h>
#include "Swarm.h"
#undef main

using namespace std;
using namespace cagin2245;

int main() 
{
	srand(time(NULL)); // Random number seed generator
	Ekran ekran;
	if (ekran.init() == false)
	{
		cout << "Error initialising SDL." << endl;
	}
	
	Swarm swarm;

	bool quit = false;
	
	while (true) // Game Loop
	{	// Update Particles
		// Draw Particles
		int elapsed = SDL_GetTicks();
		ekran.clear();
		swarm.Update();

		unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0053)) * 128);
		unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0023)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0042)) * 128);

		const Particle* const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			Particle particle = pParticles[i];

			int x = (particle.m_x +1) * Ekran::EKRAN_GENISLIGI/2;
			int y = (particle.m_y + 1) * Ekran::EKRAN_UZUNLUGU / 2;

			ekran.setPixel(x, y, red, green,blue);

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