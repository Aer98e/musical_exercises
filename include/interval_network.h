#pragma once
#include <string>

class specificIntervalName {
public:
    specificIntervalName(std::string name,
                        specificIntervalName* up = nullptr,
                        specificIntervalName* down = nullptr);
    
    std::string getName() const;
    
    specificIntervalName* getUp() const;
    specificIntervalName* getDown() const;
    void setUp(specificIntervalName* newUp);
    void setDown(specificIntervalName* newDown);
private:
    std::string name;
    specificIntervalName* up;
    specificIntervalName* down;
};

enum class Mode { Mayor, Justo };

class IntervalNetwork {
public:
    IntervalNetwork();
    static IntervalNetwork& getInstance();
    void selectMode(Mode mode);
    void up();
    void down();
    std::string calculateInterval(int desviation);
    Mode getMode();
private:
    Mode workingMode;
    specificIntervalName major;
    specificIntervalName minor;
    specificIntervalName just;
    specificIntervalName augmented;
    specificIntervalName disminished;
    specificIntervalName doubleAumented;
    specificIntervalName doubleDisminished;
    specificIntervalName* intervalSelected;
};