#ifndef PIANO
#define PIANO

#include "Instrument.hpp"

class Piano : public Instrument {
public:
    Piano();
    void jouer_note(string note, string rythme) override;
};

#endif // PIANO
