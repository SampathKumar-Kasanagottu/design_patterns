#include <stdio.h>
#include <string.h>
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

// Factory to Create Shapes
typedef struct ShapeFactory {
    Shape* (*create_shape)(const char* shape_type);
} ShapeFactory;

// Concrete Factory Function to Create Shapes
Shape* create_shape(const char* shape_type) {
    if (shape_type == NULL) {
        return NULL;
    }
    
    if (strcmp(shape_type, "Circle") == 0) {
        Circle* circle = (Circle*)malloc(sizeof(Circle));
        circle->base.draw = draw_circle;  // Assign the draw function for Circle
        circle->radius = 5;  // Default radius
        return (Shape*)circle;
    } else if (strcmp(shape_type, "Square") == 0) {
        Square* square = (Square*)malloc(sizeof(Square));
        square->base.draw = draw_square;  // Assign the draw function for Square
        square->side = 4;  // Default side length
        return (Shape*)square;
    }
    
    return NULL;  // Return NULL if shape type is not recognized
}

// Client Code Using Factory Pattern
int main() {
    ShapeFactory factory = { create_shape };  // Create a factory
    
    Shape* circle = factory.create_shape("Circle");
    Shape* square = factory.create_shape("Square");

    circle->draw(circle);  // Output: Drawing a Circle with radius 5
    square->draw(square);  // Output: Drawing a Square with side length 4

    // Free allocated memory
    free(circle);
    free(square);

    return 0;
}
