#include "Guitare.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <map>

Guitare::Guitare() : Instrument("Guitare") {}

void Guitare::jouer_note(string note, string rythme) {
    map<string, float> ryth_l = {
    { "lent", 2.0 },
    { "normal", 1.0 },
    { "rapide", 0.5 }
    };
    cout << "[Guitare - " << rythme << "] : " << note << endl;
    this_thread::sleep_for(chrono::duration<double>(0.5 * ryth_l[rythme]));
}

