#include "chord.hpp"


Chord::Chord(MuMaterial material)
{
    this->material = material;
}

MuMaterial
Chord::GenerateChordMaterial()
{
    MuMaterial chord_material = this->material;

    float duration = chord_material.Dur();
    int segments = duration / 2;

    MuMaterial segments_material = this->material.Segments(segments);
    int voices = segments_material.NumberOfVoices();

    for(int index = 0; index < voices; index++)
    {
        MuMaterial voice_material = segments_material.GetVoice(index);

        int chord_pitch = voice_material.GetFirstNote().Pitch() % 12;

        MuMaterial triad_material;
        triad_material.MajorTriad(voice_material.Dur());
        triad_material.DiatonicTranspose(0, MAJOR_MODE, chord_pitch,
                                         ASCENDING);

        chord_material.Append(1, triad_material, 0);
    }


    return chord_material;
}
