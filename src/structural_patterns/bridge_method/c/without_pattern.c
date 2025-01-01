#include <stdio.h>
#include <stdlib.h>

// OpenGL Implementation for Circle
void draw_circle_opengl(float x, float y, float radius) {
    printf("Drawing Circle using OpenGL at (%.2f, %.2f) with radius %.2f\n", x, y, radius);
}

// OpenGL Implementation for Rectangle
void draw_rectangle_opengl(float x, float y, float width, float height) {
    printf("Drawing Rectangle using OpenGL at (%.2f, %.2f) with width %.2f and height %.2f\n", x, y, width, height);
}

// DirectX Implementation for Circle
void draw_circle_directx(float x, float y, float radius) {
    printf("Drawing Circle using DirectX at (%.2f, %.2f) with radius %.2f\n", x, y, radius);
}

// DirectX Implementation for Rectangle
void draw_rectangle_directx(float x, float y, float width, float height) {
    printf("Drawing Rectangle using DirectX at (%.2f, %.2f) with width %.2f and height %.2f\n", x, y, width, height);
}

// Client Code Without Bridge Pattern
int main() {
    // Create specific shapes with their respective drawing APIs
    float x = 10.0f, y = 20.0f;
    float width = 10.0f, height = 20.0f;
    float radius = 5.0f;

    // Draw Circle using OpenGL
    draw_circle_opengl(x, y, radius);

    // Draw Rectangle using DirectX
    draw_rectangle_directx(x, y, width, height);

    // Resize and redraw shapes (no common interface, so we manually handle resizing)
    radius *= 2;  // Double the radius
    width *= 1.5f;
    height *= 1.5f;

    draw_circle_opengl(x, y, radius);
    draw_rectangle_directx(x, y, width, height);

    return 0;
}
