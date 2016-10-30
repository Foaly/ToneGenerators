#ifndef SINUSOID_INCLUDE
#define SINUSOID_INCLUDE

#include <cmath>

class Sinusoid
{
public:
    Sinusoid(double _frequency, double _amplitude, double _sampleRate) :
        amplitude(_amplitude),
        sampleRate(_sampleRate),
        phi(0.0)
    {
        frequency(_frequency);
    }

    double getNextSample()
    {
        double sample = std::sin(phi);

        phi += twoPI * m_frequency / sampleRate;

        return amplitude * sample;
    }
    
    void frequency(double frequency)
    {
        m_frequency = frequency;
    }
    
    double frequency()
    {
        return m_frequency;
    }

    double amplitude;
    double sampleRate;
    double phi;
    
private:
    double m_frequency;

};

#endif // SINUSOID_INCLUDE
