#include <stdio.h>
#include <stdlib.h>

// Abstract Shape Interface
typedef struct Shape {
    void (*draw)(struct Shape* shape);  // Function pointer for draw
} Shape;

// Concrete Shape Types: Circle and Square
typedef struct Circle {
    Shape base;  // Inheritance-like behavior
    int radius;
} Circle;

typedef struct Square {
    Shape base;  // Inheritance-like behavior
    int side;
} Square;

// Concrete Draw Functions for Circle and Square
void draw_circle(Shape* shape) {
    Circle* circle = (Circle*)shape;  // Casting Shape* to Circle*
    printf("Drawing a Circle with radius %d\n", circle->radius);
}

void draw_square(Shape* shape) {
    Square* square = (Square*)shape;  // Casting Shape* to Square*
    printf("Drawing a Square with side length %d\n", square->side);
}

// Client Code Without Factory Pattern
int main() {
    // Directly creating a Circle and a Square without using Factory
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->base.draw = draw_circle;
    circle->radius = 5;  // Set radius
    
    Square* square = (Square*)malloc(sizeof(Square));
    square->base.draw = draw_square;
    square->side = 4;  // Set side length

    circle->base.draw((Shape*)circle);  // Output: Drawing a Circle with radius 5
    square->base.draw((Shape*)square);  // Output: Drawing a Square with side length 4

    // Free allocated memory
    free(circle);
    free(square);

    return 0;
}
