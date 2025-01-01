/*
The Bridge Design Pattern is a structural pattern that decouples an abstraction from its implementation, allowing both to evolve independently. 
The main goal of the Bridge pattern is to avoid a rigid class structure that requires changes in the entire hierarchy when only one aspect of it changes.

This pattern is useful when you have:

    Multiple variations of both the abstraction and its implementation.
    You want to extend these variations independently of each other.

In the Bridge pattern, the Abstraction refers to the high-level functionality, while the Implementation refers to the low-level functionality. 
These two are connected via a bridge interface, allowing both to evolve independently.

*/

#include <stdio.h>
#include <stdlib.h>

// The Implementation interface (Drawing API)
typedef struct DrawingAPI {
    void (*draw_circle)(struct DrawingAPI* api, float x, float y, float radius);
    void (*draw_rectangle)(struct DrawingAPI* api, float x, float y, float width, float height);
} DrawingAPI;

// Concrete Implementations of DrawingAPI

// OpenGL Implementation
void draw_circle_opengl(DrawingAPI* api, float x, float y, float radius) {
    printf("Drawing Circle using OpenGL at (%.2f, %.2f) with radius %.2f\n", x, y, radius);
}

void draw_rectangle_opengl(DrawingAPI* api, float x, float y, float width, float height) {
    printf("Drawing Rectangle using OpenGL at (%.2f, %.2f) with width %.2f and height %.2f\n", x, y, width, height);
}

// DirectX Implementation
void draw_circle_directx(DrawingAPI* api, float x, float y, float radius) {
    printf("Drawing Circle using DirectX at (%.2f, %.2f) with radius %.2f\n", x, y, radius);
}

void draw_rectangle_directx(DrawingAPI* api, float x, float y, float width, float height) {
    printf("Drawing Rectangle using DirectX at (%.2f, %.2f) with width %.2f and height %.2f\n", x, y, width, height);
}

// The Abstraction interface (Shape)
typedef struct Shape {
    void (*draw)(struct Shape* shape);
    void (*resize)(struct Shape* shape, float factor);
    DrawingAPI* drawing_api;  // Bridge to Implementation
} Shape;

// Concrete Abstraction: Circle
typedef struct Circle {
    Shape base;  // Inherit from Shape
    float x, y, radius;
} Circle;

void draw_circle(Shape* shape) {
    Circle* circle = (Circle*)shape;
    shape->drawing_api->draw_circle(shape->drawing_api, circle->x, circle->y, circle->radius);
}

void resize_circle(Shape* shape, float factor) {
    Circle* circle = (Circle*)shape;
    circle->radius *= factor;
}

Circle* create_circle(DrawingAPI* drawing_api, float x, float y, float radius) {
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->base.draw = draw_circle;
    circle->base.resize = resize_circle;
    circle->base.drawing_api = drawing_api;
    circle->x = x;
    circle->y = y;
    circle->radius = radius;
    return circle;
}

// Concrete Abstraction: Rectangle
typedef struct Rectangle {
    Shape base;  // Inherit from Shape
    float x, y, width, height;
} Rectangle;

void draw_rectangle(Shape* shape) {
    Rectangle* rectangle = (Rectangle*)shape;
    shape->drawing_api->draw_rectangle(shape->drawing_api, rectangle->x, rectangle->y, rectangle->width, rectangle->height);
}

void resize_rectangle(Shape* shape, float factor) {
    Rectangle* rectangle = (Rectangle*)shape;
    rectangle->width *= factor;
    rectangle->height *= factor;
}

Rectangle* create_rectangle(DrawingAPI* drawing_api, float x, float y, float width, float height) {
    Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
    rectangle->base.draw = draw_rectangle;
    rectangle->base.resize = resize_rectangle;
    rectangle->base.drawing_api = drawing_api;
    rectangle->x = x;
    rectangle->y = y;
    rectangle->width = width;
    rectangle->height = height;
    return rectangle;
}

// Client Code
int main() {
    // Create two different drawing implementations (OpenGL and DirectX)
    DrawingAPI opengl_api = { draw_circle_opengl, draw_rectangle_opengl };
    DrawingAPI directx_api = { draw_circle_directx, draw_rectangle_directx };

    // Create shapes with different drawing implementations
    Shape* circle = (Shape*)create_circle(&opengl_api, 10.0f, 20.0f, 5.0f);
    Shape* rectangle = (Shape*)create_rectangle(&directx_api, 30.0f, 40.0f, 10.0f, 20.0f);

    // Draw the shapes
    circle->draw(circle);
    rectangle->draw(rectangle);

    // Resize and redraw the shapes
    circle->resize(circle, 2.0f);  // Double the radius
    rectangle->resize(rectangle, 1.5f);  // Increase size by 1.5 times
    circle->draw(circle);
    rectangle->draw(rectangle);

    // Free memory
    free(circle);
    free(rectangle);

    return 0;
}
