#ifndef PARTICLE_H
#define PARTICLE_H


class Particle
{
    public:
        Particle();
        virtual ~Particle();
        double m_x;
        double m_y;
        void update(int interval);




    private:
        double m_speed;
        double m_direction;
        void init();

};

#endif // PARTICLE_H
