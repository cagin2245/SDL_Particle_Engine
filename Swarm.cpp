#include "Swarm.h"

namespace cagin2245 {

	Swarm::Swarm(): lastTime(0) {
		m_pParticles = new Particle[NPARTICLES];

	}
	Swarm::~Swarm() {

		delete[] m_pParticles;
	}
	void Swarm::Update(int elapsed) {
		int interval = elapsed - lastTime;
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			m_pParticles[i].Update(interval);

		}
		lastTime = elapsed;
	}

}