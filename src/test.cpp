#include "music_funtion.h"
#include <iostream>
#include <vector>
#include <string>

int main()
{
    Scale* nova = Scale::getScale();

    nova -> randNote();
    
    std::vector <int> pattern_minor = {2, 2, 1, 2, 2, 2, 1};

    nova -> applyScalePattern(pattern_minor, -1);

    nova->print();
    
    std::cin.get();
    return 0;
}

