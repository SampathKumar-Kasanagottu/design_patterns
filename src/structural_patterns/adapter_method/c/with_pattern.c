/*

The Adapter Design Pattern is a structural pattern that allows incompatible interfaces to work 
together. The Adapter pattern acts as a bridge between two incompatible interfaces by converting one interface 
into another that the client expects. It enables you to reuse existing code and allows integration between systems 
that would otherwise not be compatible.

In C, we can implement the Adapter pattern using function pointers and structs to "adapt" different interfaces to the same expected interface.

*/


#include <stdio.h>
#include <stdlib.h>

// The Target interface (MediaPlayer) that the client expects
typedef struct MediaPlayer {
    void (*play)(struct MediaPlayer* player, const char* file_name);
} MediaPlayer;

// Adaptee 1: AudioPlayer, which has a different interface
typedef struct AudioPlayer {
    void (*play_audio)(struct AudioPlayer* player, const char* file_name);
} AudioPlayer;

// Adaptee 2: VideoPlayer, which also has a different interface
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

// Adapter for AudioPlayer to conform to MediaPlayer interface
typedef struct AudioPlayerAdapter {
    MediaPlayer base;  // Inherit MediaPlayer interface
    AudioPlayer* audio_player;  // Wrapped AudioPlayer
} AudioPlayerAdapter;

void play_audio_adapter(MediaPlayer* player, const char* file_name) {
    AudioPlayerAdapter* adapter = (AudioPlayerAdapter*)player;
    adapter->audio_player->play_audio(adapter->audio_player, file_name);
}

AudioPlayerAdapter* create_audio_player_adapter(AudioPlayer* audio_player) {
    AudioPlayerAdapter* adapter = (AudioPlayerAdapter*)malloc(sizeof(AudioPlayerAdapter));
    adapter->base.play = play_audio_adapter;
    adapter->audio_player = audio_player;
    return adapter;
}

// Adapter for VideoPlayer to conform to MediaPlayer interface
typedef struct VideoPlayerAdapter {
    MediaPlayer base;  // Inherit MediaPlayer interface
    VideoPlayer* video_player;  // Wrapped VideoPlayer
} VideoPlayerAdapter;

void play_video_adapter(MediaPlayer* player, const char* file_name) {
    VideoPlayerAdapter* adapter = (VideoPlayerAdapter*)player;
    adapter->video_player->play_video(adapter->video_player, file_name);
}

VideoPlayerAdapter* create_video_player_adapter(VideoPlayer* video_player) {
    VideoPlayerAdapter* adapter = (VideoPlayerAdapter*)malloc(sizeof(VideoPlayerAdapter));
    adapter->base.play = play_video_adapter;
    adapter->video_player = video_player;
    return adapter;
}

// Client Code
int main() {
    // Create the original players
    AudioPlayer audio_player = { play_audio };
    VideoPlayer video_player = { play_video };

    // Create adapters for both players
    MediaPlayer* audio_player_adapter = (MediaPlayer*)create_audio_player_adapter(&audio_player);
    MediaPlayer* video_player_adapter = (MediaPlayer*)create_video_player_adapter(&video_player);

    // Play audio and video using the unified MediaPlayer interface
    audio_player_adapter->play(audio_player_adapter, "song.mp3");  // Output: Playing audio file: song.mp3
    video_player_adapter->play(video_player_adapter, "movie.mp4");  // Output: Playing video file: movie.mp4

    // Free memory
    free(audio_player_adapter);
    free(video_player_adapter);

    return 0;
}
