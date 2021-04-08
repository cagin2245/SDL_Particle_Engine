#include "Swarm.h"

namespace cagin2245 {

	Swarm::Swarm() {
		m_pParticles = new Particle[NPARTICLES];

	}
	Swarm::~Swarm() {

		delete[] m_pParticles;
	}
	void Swarm::Update() {
		for (int i = 0; i < Swarm::NPARTICLES; i++)
		{
			m_pParticles[i].Update();

		}
	}

}