#ifndef TRIANGLE_INCLUDE
#define TRIANGLE_INCLUDE

#include <cmath>

class Triangle
{
public:
    Triangle(double _frequency, double _amplitude, double _sampleRate) :
        frequency(_frequency),
        amplitude(_amplitude),
        sampleRate(_sampleRate),
        m_nextSample(0.0),
        m_sign(1)
    {

    }

    double getNextSample()
    {
        double sample = m_nextSample;
        
        double step = 4.0 * frequency / sampleRate;

        m_nextSample += step * m_sign;

        if (m_nextSample > 1.0)
        {
            m_nextSample = 1.0 - (m_nextSample - 1.0); // wrap around
            m_sign = -1;
        }
        else if (m_nextSample < -1.0)
        {
            m_nextSample = -1.0 - (m_nextSample + 1.0); // wrap around
            m_sign = 1;
        }

        return amplitude * sample;
    }

    double frequency;
    double amplitude;
    double sampleRate;

private:
    double m_nextSample;
    signed char m_sign;
};

#endif // TRIANGLE_INCLUDE
