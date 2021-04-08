#pragma once

#include "Particle.h"

namespace cagin2245{

	class Swarm
	{
	public:
		const static int NPARTICLES =  100;
	private:
		Particle*  m_pParticles;
		int lastTime;
	public:
		Swarm();
		virtual ~Swarm();
		const Particle* const getParticles() { return m_pParticles; };
		void Update(int elapsed);

	};
	}
