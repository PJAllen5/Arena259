#include "viper.h"

Creature makeViper()
{
    std::string n = "Viper";
    int h = 80;
    int d = 21;
    return Creature(n, h, d);
}