#include <stdio.h>
#include <stdlib.h>

// AudioPlayer with its own interface
typedef struct AudioPlayer {
    void (*play_audio)(struct AudioPlayer* player, const char* file_name);
} AudioPlayer;

// VideoPlayer with its own interface
typedef struct VideoPlayer {
    void (*play_video)(struct VideoPlayer* player, const char* file_name);
} VideoPlayer;

// Concrete Implementation of AudioPlayer
void play_audio(AudioPlayer* player, const char* file_name) {
    printf("Playing audio file: %s\n", file_name);
}

// Concrete Implementation of VideoPlayer
void play_video(VideoPlayer* player, const char* file_name) {
    printf("Playing video file: %s\n", file_name);
}

// Client Code without Adapter Pattern
int main() {
    // Create the original players
    AudioPlayer audio_player = { play_audio };
    VideoPlayer video_player = { play_video };

    // Directly use the methods of the players
    audio_player.play_audio(&audio_player, "song.mp3");  // Output: Playing audio file: song.mp3
    video_player.play_video(&video_player, "movie.mp4");  // Output: Playing video file: movie.mp4

    return 0;
}
