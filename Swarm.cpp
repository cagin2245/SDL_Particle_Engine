#include "Swarm.h"

namespace cagin2245 {

	Swarm::Swarm() {
		m_pParticles = new Particle[NPARTICLES];

	}
	Swarm::~Swarm() {

		delete[] m_pParticles;
	}

}