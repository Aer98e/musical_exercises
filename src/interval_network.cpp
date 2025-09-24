#include "interval_network.h"
#include <stdexcept>

specificIntervalName::specificIntervalName(std::string name,
                                           specificIntervalName* up,
                                           specificIntervalName* down)
    : name(std::move(name)), up(up), down(down) {}

std::string specificIntervalName::getName() const { return name; }
specificIntervalName* specificIntervalName::getUp() const { return up; }
specificIntervalName* specificIntervalName::getDown() const { return down; }
void specificIntervalName::setUp(specificIntervalName* newUp) { up = newUp; }
void specificIntervalName::setDown(specificIntervalName* newDown) { down = newDown; }

IntervalNetwork::IntervalNetwork()
    : major("Mayor"),
      minor("Menor"),
      just("Justo"),
      augmented("Aumentado"),
      disminished("Disminuido"),
      intervalSelected(nullptr)
{
    major.setUp(&augmented);
    major.setDown(&minor);

    minor.setUp(&major);
    minor.setDown(&disminished);

    just.setDown(&disminished);
    just.setUp(&augmented);
}

IntervalNetwork& IntervalNetwork::getInstance() {
    static IntervalNetwork instance;
    return instance;
}

void IntervalNetwork::selectMode(Mode mode) {
    switch (mode) {
        case Mode::Mayor:
            intervalSelected = &major;
            disminished.setUp(&minor);
            augmented.setDown(&major);
            break;
            
        case Mode::Justo:
            intervalSelected = &just;
            disminished.setUp(&just);
            augmented.setDown(&just);
            break;
    }
}

void IntervalNetwork::up() {
    auto temp = intervalSelected->getUp();
    if (!temp) throw std::runtime_error("No existe intervalo más alto.");
    intervalSelected = temp;
}

void IntervalNetwork::down() {
    auto temp = intervalSelected->getDown();
    if (!temp) throw std::runtime_error("No existe intervalo más bajo.");
    intervalSelected = temp;
}

std::string IntervalNetwork::calculateInterval(int desviation) {
    if (intervalSelected == nullptr) {
        throw std::runtime_error("No se ha seleccionado ningún modo.");
    }
    while (desviation != 0) {
        if (desviation < 0) {
            down();
            desviation += 1;
        } else {
            up();
            desviation -= 1;
        }
    }
    return intervalSelected->getName();
}