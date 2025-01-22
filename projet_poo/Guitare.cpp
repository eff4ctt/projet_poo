#include "Guitare.hpp"

Guitare::Guitare() : Instrument("Guitare") {}

void Guitare::jouer_note(string note, string rythme) {
    cout << "[Guitare - " << rythme << "] : " << note << endl;
}

