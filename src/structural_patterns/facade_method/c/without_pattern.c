#include <stdio.h>
#include <stdlib.h>

// Subsystem: DVD Player
typedef struct {
    char* movieName;
} DVDPlayer;

void dvdPlayerOn(DVDPlayer* dvdPlayer) {
    printf("DVD Player is on.\n");
}

void dvdPlayerOff(DVDPlayer* dvdPlayer) {
    printf("DVD Player is off.\n");
}

void playMovie(DVDPlayer* dvdPlayer, const char* movie) {
    dvdPlayer->movieName = (char*)movie;
    printf("Playing movie: %s\n", dvdPlayer->movieName);
}

// Subsystem: Projector
typedef struct {
} Projector;

void projectorOn(Projector* projector) {
    printf("Projector is on.\n");
}

void projectorOff(Projector* projector) {
    printf("Projector is off.\n");
}

// Subsystem: Sound System
typedef struct {
} SoundSystem;

void soundSystemOn(SoundSystem* soundSystem) {
    printf("Sound System is on.\n");
}

void soundSystemOff(SoundSystem* soundSystem) {
    printf("Sound System is off.\n");
}

// Subsystem: Lights
typedef struct {
} Lights;

void lightsDim(Lights* lights) {
    printf("Lights dimmed.\n");
}

void lightsOn(Lights* lights) {
    printf("Lights on.\n");
}

// Client code (without facade)
int main() {
    DVDPlayer dvdPlayer;
    Projector projector;
    SoundSystem soundSystem;
    Lights lights;

    // Initialize and start watching a movie
    dvdPlayerOn(&dvdPlayer);
    projectorOn(&projector);
    soundSystemOn(&soundSystem);
    lightsDim(&lights);
    playMovie(&dvdPlayer, "Inception");

    printf("\nMovie is playing...\n");

    // Ending the movie
    printf("\nEnding movie...\n");
    dvdPlayerOff(&dvdPlayer);
    projectorOff(&projector);
    soundSystemOff(&soundSystem);
    lightsOn(&lights);

    return 0;
}
