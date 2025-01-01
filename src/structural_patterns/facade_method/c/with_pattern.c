/*

 The Facade Design Pattern is used to provide a simplified interface to a complex subsystem. 
 It defines a higher-level interface that makes a subsystem easier to use.

*/

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

// Facade: Home Theater
typedef struct {
    DVDPlayer dvdPlayer;
    Projector projector;
    SoundSystem soundSystem;
    Lights lights;
} HomeTheaterFacade;

void initializeHomeTheater(HomeTheaterFacade* homeTheater) {
    dvdPlayerOn(&homeTheater->dvdPlayer);
    projectorOn(&homeTheater->projector);
    soundSystemOn(&homeTheater->soundSystem);
    lightsDim(&homeTheater->lights);
}

void watchMovie(HomeTheaterFacade* homeTheater, const char* movie) {
    playMovie(&homeTheater->dvdPlayer, movie);
    printf("Get ready to watch the movie...\n");
}

void endMovie(HomeTheaterFacade* homeTheater) {
    printf("Movie has ended.\n");
    dvdPlayerOff(&homeTheater->dvdPlayer);
    projectorOff(&homeTheater->projector);
    soundSystemOff(&homeTheater->soundSystem);
    lightsOn(&homeTheater->lights);
}

int main() {
    HomeTheaterFacade homeTheater;
    
    printf("Initializing Home Theater...\n");
    initializeHomeTheater(&homeTheater);

    printf("\nWatching Movie...\n");
    watchMovie(&homeTheater, "Inception");

    printf("\nEnding Movie...\n");
    endMovie(&homeTheater);
    
    return 0;
}
