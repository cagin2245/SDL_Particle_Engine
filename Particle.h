#pragma once

namespace cagin2245 {
	class Particle
	{
	public:
		double m_x; // "maybe between two pixels "
		double m_y;
		double m_xspeed;
		double m_yspeed;
	public:
		Particle();
		virtual ~Particle();
		void Update();
	};

}