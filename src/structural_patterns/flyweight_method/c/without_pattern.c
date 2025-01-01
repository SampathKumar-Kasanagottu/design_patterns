#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Circle structure (no Flyweight pattern)
typedef struct {
    char* color;  // Color of the circle (intrinsic state)
    int x, y;     // Position of the circle (extrinsic state)
} Circle;

void drawCircle(Circle* circle) {
    printf("Circle [Color: %s] at position (%d, %d)\n", circle->color, circle->x, circle->y);
}

int main() {
    // Create new circles (each with its own memory)
    Circle* redCircle1 = (Circle*)malloc(sizeof(Circle));
    redCircle1->color = strdup("Red");
    redCircle1->x = 10;
    redCircle1->y = 20;

    Circle* blueCircle = (Circle*)malloc(sizeof(Circle));
    blueCircle->color = strdup("Blue");
    blueCircle->x = 30;
    blueCircle->y = 40;

    Circle* redCircle2 = (Circle*)malloc(sizeof(Circle));
    redCircle2->color = strdup("Red");
    redCircle2->x = 50;
    redCircle2->y = 60;

    // Draw the circles
    drawCircle(redCircle1);
    drawCircle(blueCircle);
    drawCircle(redCircle2);

    // Free the memory
    free(redCircle1->color);
    free(redCircle1);
    free(blueCircle->color);
    free(blueCircle);
    free(redCircle2->color);
    free(redCircle2);

    return 0;
}
