#ifndef SINUSOID_INCLUDE
#define SINUSOID_INCLUDE

#include <cmath>

class Sinusoid
{
public:
    Sinusoid(double _frequency, double _amplitude, double _sampleRate) :
        frequency(_frequency),
        amplitude(_amplitude),
        sampleRate(_sampleRate),
        phi(0.0)
    {

    }

    double getNextSample()
    {
        double sample = std::sin(phi);

        phi += twoPI * frequency / sampleRate;

        return amplitude * sample;
    }

    double frequency;
    double amplitude;
    double sampleRate;
    double phi;
};

#endif // SINUSOID_INCLUDE
