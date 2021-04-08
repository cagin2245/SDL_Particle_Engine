#include "Particle.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
namespace cagin2245 {

	Particle::Particle():m_x(0),m_y(0){

		m_direction = 2* M_PI * rand() / RAND_MAX;
		m_speed = 0.4* rand() / RAND_MAX;

	};
	Particle::~Particle() {



	};
	void Particle::Update(int interval) {
		
		double xspeed = m_speed * cos(m_direction);
		double yspeed = m_speed * sin(m_direction);

		m_x += xspeed * interval;
		m_y += yspeed * interval;
		
	}
}