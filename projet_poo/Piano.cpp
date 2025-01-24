#include "Piano.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <map>
Piano::Piano() : Instrument("Piano") {}

void Piano::jouer_note(string note, string rythme) {
    map<string, float> ryth_l = {
    { "lent", 2.0 },
    { "normal", 1.0 },
    { "rapide", 0.5 }
    };
    cout << "[Piano - " << rythme << "] : " << note << endl;
    this_thread::sleep_for(chrono::duration<double>(0.5 * ryth_l[rythme]));
}


