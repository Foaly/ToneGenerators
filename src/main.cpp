#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <cmath>
#include <iostream>
#include <vector>

const double PI = std::atan(1.0) * 4.0;
const double twoPI = 2.0 * PI;

#include "Sinusoid.hpp"
#include "Triangle.hpp"


int main() {
    const float        lengthInSeconds = 1.5f;
    const unsigned int SAMPLE_RATE     = 44100;
    const unsigned int AMPLITUDE       = 30000;

    std::vector<sf::Int16> rawSamples(lengthInSeconds * SAMPLE_RATE, 0);

    double frequency = 190.0;
    Sinusoid sinus(frequency, AMPLITUDE, SAMPLE_RATE);
    Triangle triangle(frequency, AMPLITUDE, SAMPLE_RATE);


    for (auto& rawSample: rawSamples)
    {
        rawSample = triangle.getNextSample();
        triangle.frequency *= 0.9999;
    }

    // abhängig von der Frequenz ausfaden (4 * phase)

    sf::SoundBuffer Buffer;
    if (!Buffer.loadFromSamples(rawSamples.data(), rawSamples.size(), 1, SAMPLE_RATE)) {
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
