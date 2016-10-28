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
        phi(0.0),
        previousSample(0.0),
        sign(1)
    {

    }

    double getNextSample()
    {
        double step = twoPI * frequency / sampleRate;

        previousSample += step * sign * 0.5;

        if (previousSample > 1.0)
        {
            previousSample -= previousSample - 1.0; // wrap around
            sign = -1;
        }
        else if (previousSample < -1.0)
        {
            previousSample -= previousSample + 1.0; // wrap around
            sign = 1;
        }

        return amplitude * previousSample;
    }

    double frequency;
    double amplitude;
    double sampleRate;
    double phi;

private:
    double previousSample;
    signed char sign;
};

#endif // TRIANGLE_INCLUDE
