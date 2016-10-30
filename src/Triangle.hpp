#ifndef TRIANGLE_INCLUDE
#define TRIANGLE_INCLUDE

#include <cmath>

class Triangle
{
public:
    Triangle(double _frequency, double _amplitude, double _sampleRate) :
        amplitude(_amplitude),
        sampleRate(_sampleRate),
        m_nextSample(0.0),
        m_sign(1)
    {
        frequency(_frequency);
    }

    double getNextSample()
    {
        double sample = m_nextSample;
        
        m_nextSample += m_step * m_sign;

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
    
    void frequency(double frequency)
    {
        m_frequency = frequency;
        m_step = 4.0 * m_frequency / sampleRate;
    }
    
    double frequency()
    {
        return m_frequency;
    }

    double amplitude;
    double sampleRate;

private:
    double m_frequency;
    double m_nextSample;
    signed char m_sign;
    double m_step;
};

#endif // TRIANGLE_INCLUDE
