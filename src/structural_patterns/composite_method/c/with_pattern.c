/*

The Composite Design Pattern is a structural pattern that allows you to treat individual objects and compositions of objects uniformly. 
This is useful when you have a tree-like structure, where individual objects (leaf nodes) and collections of objects (composite nodes) can be treated similarly.

For instance, in a file system, a file (a leaf) and a directory (a composite object that contains files or other directories) can both be treated in a similar way.


*/

#include <stdio.h>
#include <stdlib.h>

// Component Interface (Shape)
typedef struct Shape {
    void (*draw)(struct Shape*); // Virtual function for drawing
} Shape;

// Leaf: Circle
typedef struct {
    Shape base; // Inheritance (Circle "is a" Shape)
} Circle;

void drawCircle(Shape* shape) {
    printf("Drawing a Circle\n");
}

Circle* createCircle() {
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->base.draw = drawCircle; // Assign the function pointer
    return circle;
}

// Leaf: Rectangle
typedef struct {
    Shape base; // Inheritance (Rectangle "is a" Shape)
} Rectangle;

void drawRectangle(Shape* shape) {
    printf("Drawing a Rectangle\n");
}

Rectangle* createRectangle() {
    Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
    rectangle->base.draw = drawRectangle; // Assign the function pointer
    return rectangle;
}

// Composite: DrawingGroup (can hold multiple shapes)
typedef struct {
    Shape base;  // Inheritance (DrawingGroup "is a" Shape)
    Shape** children;
    int count;
} DrawingGroup;

void drawDrawingGroup(Shape* shape) {
    DrawingGroup* group = (DrawingGroup*)shape;
    printf("Drawing Group contains:\n");
    for (int i = 0; i < group->count; i++) {
        group->children[i]->draw(group->children[i]);
    }
}

DrawingGroup* createDrawingGroup() {
    DrawingGroup* group = (DrawingGroup*)malloc(sizeof(DrawingGroup));
    group->base.draw = drawDrawingGroup;
    group->children = NULL;
    group->count = 0;
    return group;
}

void addShapeToGroup(DrawingGroup* group, Shape* shape) {
    group->children = realloc(group->children, sizeof(Shape*) * (group->count + 1));
    group->children[group->count++] = shape;
}

// Client code to demonstrate the composite pattern
int main() {
    Circle* circle1 = createCircle();
    Rectangle* rect1 = createRectangle();
    
    DrawingGroup* group = createDrawingGroup();
    addShapeToGroup(group, (Shape*)circle1);
    addShapeToGroup(group, (Shape*)rect1);

    // Draw individual shapes and the composite group
    circle1->base.draw((Shape*)circle1);
    rect1->base.draw((Shape*)rect1);
    group->base.draw((Shape*)group);

    free(circle1);
    free(rect1);
    free(group->children);
    free(group);

    return 0;
}
