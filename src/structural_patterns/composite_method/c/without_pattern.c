#include <stdio.h>
#include <stdlib.h>

// Shape structure without using composite design pattern
typedef struct {
    int type; // 0: Circle, 1: Rectangle
} Shape;

// Function to draw a circle
void drawCircle(Shape* shape) {
    printf("Drawing a Circle\n");
}

// Function to draw a rectangle
void drawRectangle(Shape* shape) {
    printf("Drawing a Rectangle\n");
}

// Function to draw a group (handles only simple shapes here)
void drawGroup(Shape* shapes[], int count) {
    printf("Drawing Group of Shapes:\n");
    for (int i = 0; i < count; i++) {
        if (shapes[i]->type == 0) {
            drawCircle(shapes[i]);
        } else if (shapes[i]->type == 1) {
            drawRectangle(shapes[i]);
        }
    }
}

int main() {
    // Create individual shapes
    Shape circle1 = {0}; // Circle
    Shape rect1 = {1};   // Rectangle

    // Add shapes to an array to simulate a group (but it is just an array of different shapes)
    Shape* group[2] = {&circle1, &rect1};
    
    // Draw individual shapes and group of shapes
    drawCircle(&circle1);
    drawRectangle(&rect1);
    drawGroup(group, 2);

    return 0;
}
