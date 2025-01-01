/*

The Flyweight Design Pattern is a structural pattern that allows you to minimize memory usage by sharing common objects between multiple clients,
 rather than creating duplicate objects. It is useful when you have a large number of objects that share common properties, and you want to optimize
  the memory usage by sharing these properties rather than duplicating them.

In the Flyweight pattern, the objects are divided into two categories:

    Intrinsic State: The state that is shared and can be safely stored in a shared object.
    Extrinsic State: The state that is unique to a particular object and is passed to the Flyweight objects when needed.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Flyweight interface (abstract class)
typedef struct Shape Shape;
struct Shape {
    void (*draw)(Shape* shape, int x, int y);  // Draw the shape at coordinates (x, y)
};

// Concrete Flyweight: Circle
typedef struct {
    Shape shape;  // Inherited from Shape
    char* color;  // Intrinsic state (shared)
} Circle;

void drawCircle(Shape* shape, int x, int y) {
    Circle* circle = (Circle*)shape;
    printf("Circle [Color: %s] at position (%d, %d)\n", circle->color, x, y);
}

// Flyweight Factory
typedef struct {
    Circle* circlePool[10];  // Pool of circles
    int poolSize;
} ShapeFactory;

// Create or retrieve a Circle from the pool
Shape* getCircle(ShapeFactory* factory, const char* color) {
    for (int i = 0; i < factory->poolSize; i++) {
        if (strcmp(factory->circlePool[i]->color, color) == 0) {
            return (Shape*)factory->circlePool[i];  // Return the shared circle
        }
    }

    // If the circle doesn't exist in the pool, create a new one
    if (factory->poolSize < 10) {
        Circle* newCircle = (Circle*)malloc(sizeof(Circle));
        newCircle->color = strdup(color);
        newCircle->shape.draw = drawCircle;
        factory->circlePool[factory->poolSize++] = newCircle;
        return (Shape*)newCircle;
    }

    printf("Circle pool full!\n");
    return NULL;  // In case the pool is full (in a real case, we would handle this more gracefully)
}

int main() {
    ShapeFactory factory = { .poolSize = 0 };

    // Create and reuse circle objects from the factory
    Shape* redCircle1 = getCircle(&factory, "Red");
    Shape* blueCircle = getCircle(&factory, "Blue");
    Shape* redCircle2 = getCircle(&factory, "Red");

    // Draw the circles
    redCircle1->draw(redCircle1, 10, 20);
    blueCircle->draw(blueCircle, 30, 40);
    redCircle2->draw(redCircle2, 50, 60);

    // Clean up
    for (int i = 0; i < factory.poolSize; i++) {
        free(factory.circlePool[i]->color);
        free(factory.circlePool[i]);
    }

    return 0;
}
