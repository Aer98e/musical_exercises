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
      doubleAumented("Doble aumentado"),
      doubleDisminished("Doble disminuido"),
      intervalSelected(nullptr)
{
    major.setUp(&augmented);
    major.setDown(&minor);

    minor.setUp(&major);
    minor.setDown(&disminished);

    just.setUp(&augmented);
    just.setDown(&disminished);

    disminished.setDown(&doubleDisminished);
    augmented.setUp(&doubleAumented);    
    
    doubleDisminished.setUp(&disminished);
    doubleAumented.setDown(&augmented);
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
    workingMode = mode;
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

    if (desviation < 0){
        for (int i; i<std::abs(desviation); i++){
            down();
        }
    }else{
        for (int i; i<std::abs(desviation); i++){
            up();
        }
    }

    return intervalSelected->getName();
}

Mode IntervalNetwork::getMode(){ return workingMode; }