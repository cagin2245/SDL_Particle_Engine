#pragma once
#include <SDL.h>

namespace cagin2245 {
	class Ekran
	{
	public:
		const static int EKRAN_GENISLIGI = 800;
		const static int EKRAN_UZUNLUGU = 600;

	private: // m_ ----> member
		SDL_Window * m_window;
		SDL_Renderer* m_renderer;
		SDL_Texture* m_texture;
		Uint32* m_buffer;
	public:
		Ekran();
		bool init();
		void update();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		bool processEvents();
		void close();
		void clear();

	};
}