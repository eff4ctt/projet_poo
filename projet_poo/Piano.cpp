#include "Piano.hpp"

Piano::Piano() : Instrument("Piano") {}

void Piano::jouer_note(string note, string rythme) {
    cout << "[Piano - " << rythme << "] : " << note << endl;
}


