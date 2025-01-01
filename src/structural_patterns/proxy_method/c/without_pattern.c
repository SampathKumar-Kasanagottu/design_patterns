#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Real Subject
typedef struct {
    char* filename;  // File to be loaded
} RealImage;

void loadImage(RealImage* realImage) {
    printf("Loading image from file: %s\n", realImage->filename);
}

void displayRealImage(RealImage* realImage) {
    loadImage(realImage);
    printf("Displaying image: %s\n", realImage->filename);
}

RealImage* createRealImage(const char* filename) {
    RealImage* realImage = (RealImage*)malloc(sizeof(RealImage));
    realImage->filename = strdup(filename);
    return realImage;
}

int main() {
    // Create a real image (always loads the image)
    RealImage* image1 = createRealImage("image1.jpg");

    // Display the image (loading will happen each time)
    printf("First display call:\n");
    displayRealImage(image1);

    // Display the image again (loading will happen each time)
    printf("\nSecond display call:\n");
    displayRealImage(image1);

    // Clean up memory
    free(image1->filename);
    free(image1);

    return 0;
}
