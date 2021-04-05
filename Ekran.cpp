#include <iostream>
#include "Ekran.h"


namespace cagin2245
{
	Ekran::Ekran() : m_window(NULL),m_renderer(NULL),m_texture(NULL),m_buffer(NULL) {
		
	}
	bool Ekran::init() {
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			return false;
		}

		m_window = SDL_CreateWindow("Partikul Patlama Efekti", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, EKRAN_GENISLIGI, EKRAN_UZUNLUGU, SDL_WINDOW_SHOWN);
		if (m_window == NULL)
		{
			printf("Pencere oluþturulamadý %s\n", SDL_GetError());
			SDL_Quit();
			return false;
		}
		m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_PRESENTVSYNC);
		m_texture = SDL_CreateTexture(m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, EKRAN_GENISLIGI, EKRAN_UZUNLUGU);

		if (m_renderer == NULL)
		{
			
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}
		if (m_texture == NULL)
		{
			
			SDL_DestroyRenderer(m_renderer);
			SDL_DestroyWindow(m_window);
			SDL_Quit();
			return false;
		}

		Uint32* buffer = new Uint32[EKRAN_GENISLIGI * EKRAN_UZUNLUGU * sizeof(Uint32)];

		memset(buffer, 0, EKRAN_GENISLIGI * EKRAN_UZUNLUGU * sizeof(Uint32));


		for (int i = 0; i < EKRAN_GENISLIGI * EKRAN_GENISLIGI; i++)
		{
			buffer[i] = 0x0FF0FF;
		}

		SDL_UpdateTexture(m_texture, NULL, buffer, EKRAN_GENISLIGI * sizeof(Uint32));
		SDL_RenderClear(m_renderer);
		SDL_RenderCopy(m_renderer, m_texture, NULL, NULL);
		SDL_RenderPresent(m_renderer);

		return true;
	}
	bool Ekran::processEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event));
		if (event.type == SDL_QUIT)
		{
			return false;
		}
		return true;
	}
	void Ekran::close() {
		delete[] m_buffer;
		SDL_DestroyRenderer(m_renderer);
		SDL_DestroyTexture(m_texture);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}