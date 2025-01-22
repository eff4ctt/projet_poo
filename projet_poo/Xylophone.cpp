#include "Xylophone.hpp"

Xylophone::Xylophone() : Instrument("Xylophone") {}

void Xylophone::jouer_note(string note, string rythme) {
    cout << "[Xylophone - " << rythme << "] : " << note << endl;
}


