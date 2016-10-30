#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <cmath>
#include <iostream>
#include <vector>
#include <functional>

const double PI = std::atan(1.0) * 4.0;
const double twoPI = 2.0 * PI;

#include "Sinusoid.hpp"
#include "Triangle.hpp"


int main() {
    const float        lengthInSeconds = 1.5f;
    const unsigned int SAMPLE_RATE     = 44100;

    std::vector<double> rawSamples(lengthInSeconds * SAMPLE_RATE, 0.0);

    double frequency = 190.0;
    Sinusoid sinus(frequency, 0.9, SAMPLE_RATE);
    Triangle triangle(frequency, 0.9, SAMPLE_RATE);


    for (auto& rawSample: rawSamples)
    {
        rawSample = sinus.getNextSample();
        sinus.frequency *= 0.9999;
    }
    
    // TODO: abhängig von der Frequenz ausfaden (4 * phase)
    
    std::vector<sf::Int16> intSamples(rawSamples.size(), 0);
    
    std::transform(rawSamples.begin(), rawSamples.end(), intSamples.begin(),
                   [](double sample)
                   {
                       return sample * 32767;
                   });
    

    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromSamples(intSamples.data(), intSamples.size(), 1, SAMPLE_RATE)) {
        std::cerr << "Loading failed!" << std::endl;
        return 1;
    }

    sf::Sound sound;
    sound.setBuffer(Buffer);
    sound.setLoop(true);
    sound.play();

    while (true) {
        if (sound.getStatus() == sf::Sound::Stopped)
            break;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            break;

        sf::sleep(sf::milliseconds(100));
    }
    return 0;
}
