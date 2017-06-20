#ifndef _CHORD_H_
#define _CHORD_H_

#include "MuMaterial.h"

class Chord
{
public:
    Chord (MuMaterial material);

    MuMaterial GenerateChordMaterial ();

private:

    MuMaterial material;
};

#endif

