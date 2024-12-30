#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vehicle Structure
typedef struct {
    void (*drive)(void);
    void (*color)(void);
} Vehicle;

// Color Structure
typedef struct {
    void (*fill)(void);
} Color;

// Concrete Vehicle Types
void car_drive() {
    printf("Driving a car...\n");
}

void bike_drive() {
    printf("Riding a bike...\n");
}

// Concrete Color Types
void red_fill() {
    printf("Coloring with red...\n");
}

void blue_fill() {
    printf("Coloring with blue...\n");
}

// Client Code: Direct Creation without Abstract Factory
int main() {
    // Creating a Car and Red Color
    Vehicle car;
    car.drive = car_drive;
    car.color = red_fill;

    Color red;
    red.fill = red_fill;

    car.drive();  // Output: Driving a car...
    car.color();  // Output: Coloring with red...

    // Creating a Bike and Blue Color
    Vehicle bike;
    bike.drive = bike_drive;
    bike.color = blue_fill;

    Color blue;
    blue.fill = blue_fill;

    bike.drive();  // Output: Riding a bike...
    bike.color();  // Output: Coloring with blue...

    return 0;
}
