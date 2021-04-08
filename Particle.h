#pragma once

namespace cagin2245 {
	class Particle
	{
	public:
		double m_x; // "maybe between two pixels "
		double m_y;
		double m_speed;
		double m_direction;
	public:
		Particle();
		virtual ~Particle();
		void Update(int interval);
	};

}