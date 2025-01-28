#ifndef CONTREBASSE
#define CONTREBASSE

#include "Instrument.hpp"

class ContreBasse : public Instrument {
public:
    ContreBasse();
    void jouer_note(string note, string rythme) override;
};

#endif // CONTREBASSE
