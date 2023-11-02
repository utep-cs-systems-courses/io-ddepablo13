#ifndef SOUND_H
#define SOUND_H

/**
 * Initialize the sound system.
 */
void init_sound();

/**
 * Generate a sound with a given note.
 *
 * @param note The frequency or identifier of the note to play.
 */
void generate_sound(unsigned char note);

/**
 * Stop the currently playing sound.
 */
void stop_sound();

#endif // SOUND_H
