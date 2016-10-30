#ifndef SAWTOOTH_INCLUDE
#define SAWTOOTH_INCLUDE

#include <cmath>

/**
 * \brief A sawtooth wave generator. A sawtooth wave ramps upward and then 
 *        sharply drops. See https://en.wikipedia.org/wiki/Sawtooth_wave
 */

class Sawtooth
{
public:
    Sawtooth(double _frequency, double _amplitude, double _sampleRate) :
    frequency(_frequency),
    amplitude(_amplitude),
    sampleRate(_sampleRate),
    m_nextSample(-1.0)
    {
        
    }
    
    double getNextSample()
    {
        double sample = m_nextSample;
        
        double step = 2.0 * frequency / sampleRate; // TODO: calculate only when frequency changes
        
        m_nextSample += step;
        
        if (m_nextSample > 1.0)
        {
            m_nextSample -= 2.0; // wrap around
        }
        
        return amplitude * sample;
    }
    
    double frequency;
    double amplitude;
    double sampleRate;
    
private:
    double m_nextSample;
};

#endif // SAWTOOTH_INCLUDE
