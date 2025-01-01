/*

The Proxy Design Pattern is a structural design pattern that provides an object representing another object. 
It acts as an intermediary or placeholder to control access to the original object. 
The proxy object controls the access to the real object in various ways, such as by lazy loading, access control, or logging method calls.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // Include string.h for malloc and strcpy

// Abstract Subject (Image Interface)
typedef struct Image {
    void (*display)(struct Image* image);  // Function pointer for display
} Image;

// Real Subject: RealImage
typedef struct {
    Image base;      // Base class (Image) in a struct (simulating inheritance)
    char* filename;  // File to be loaded (intrinsic state)
} RealImage;

// Function to load image from file
void loadImage(RealImage* realImage) {
    printf("Loading image from file: %s\n", realImage->filename);
}

// Function to display the real image
void displayRealImage(Image* image) {
    RealImage* realImage = (RealImage*)image;
    loadImage(realImage);
    printf("Displaying image: %s\n", realImage->filename);
}

// RealImage constructor
RealImage* createRealImage(const char* filename) {
    RealImage* realImage = (RealImage*)malloc(sizeof(RealImage));
    realImage->filename = strdup(filename);  // Allocate and copy filename
    realImage->base.display = displayRealImage;  // Assign the display function
    return realImage;
}

// Proxy class: ProxyImage
typedef struct {
    Image base;      // Base class (Image) for ProxyImage
    Image* realImage;  // RealImage (Lazy-loaded)
    char* filename;  // Filename for the image (to be passed to the RealImage)
} ProxyImage;

// Function to display image via Proxy
void displayProxyImage(Image* image) {
    ProxyImage* proxyImage = (ProxyImage*)image;

    // Lazy initialization of the real image
    if (proxyImage->realImage == NULL) {
        proxyImage->realImage = (Image*)createRealImage(proxyImage->filename);
    }

    // Forward the display call to the real image
    proxyImage->realImage->display(proxyImage->realImage);
}

// ProxyImage constructor
ProxyImage* createProxyImage(const char* filename) {
    ProxyImage* proxyImage = (ProxyImage*)malloc(sizeof(ProxyImage));
    proxyImage->realImage = NULL;  // Initially, realImage is NULL
    proxyImage->filename = strdup(filename);  // Store the filename
    proxyImage->base.display = displayProxyImage;  // Forward display to the proxy
    return proxyImage;
}

// Custom strdup function for older compilers that don't support it
char* my_strdup(const char* str) {
    size_t len = strlen(str) + 1;  // Allocate space for string + null-terminator
    char* copy = (char*)malloc(len);
    if (copy) {
        strcpy(copy, str);  // Copy the string
    }
    return copy;
}

int main() {
    // Create a proxy for an image
    Image* image1 = (Image*)createProxyImage("image1.jpg");

    // Display the image (lazy loading happens here)
    printf("First display call:\n");
    image1->display(image1);

    // Display the image again (no loading this time)
    printf("\nSecond display call:\n");
    image1->display(image1);

    // Clean up memory
    ProxyImage* proxyImage = (ProxyImage*)image1;
    
    // Free resources for the real image inside the proxy
    if (proxyImage->realImage) {
        RealImage* realImage = (RealImage*)proxyImage->realImage;
        free(realImage->filename);  // Free filename of real image
        free(realImage);  // Free the RealImage
    }
    
    // Free the proxy's filename and the proxy itself
    free(proxyImage->filename);
    free(proxyImage);

    return 0;
}
