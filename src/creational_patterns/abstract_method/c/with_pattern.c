#include <stdio.h>
#include <stdlib.h>

// Abstract Vehicle
typedef struct Vehicle {
    void (*drive)(struct Vehicle* vehicle);  // Function pointer for drive
    void (*color)(struct Vehicle* vehicle);  // Function pointer for color
} Vehicle;

// Abstract Color
typedef struct Color {
    void (*fill)(struct Color* color);  // Function pointer for fill
} Color;

// Concrete Vehicle Types
typedef struct Car {
    Vehicle base;  // Inheritance-like behavior
} Car;

typedef struct Bike {
    Vehicle base;  // Inheritance-like behavior
} Bike;

// Concrete Color Types
typedef struct Red {
    Color base;  // Inheritance-like behavior
} Red;

typedef struct Blue {
    Color base;  // Inheritance-like behavior
} Blue;

// Concrete function implementations for Car and Bike
void car_drive(Vehicle* vehicle) {
    printf("Driving a car...\n");
}

void bike_drive(Vehicle* vehicle) {
    printf("Riding a bike...\n");
}

// Concrete function implementations for Red and Blue
void red_fill(Color* color) {
    printf("Coloring with red...\n");
}

void blue_fill(Color* color) {
    printf("Coloring with blue...\n");
}

// These functions need to convert Vehicle* to Color* appropriately.
void car_color(Vehicle* vehicle) {
    // For this example, we're assuming cars are red.
    Red* red = (Red*)malloc(sizeof(Red));
    red->base.fill = red_fill; // Assign color fill behavior
    red->base.fill(&red->base); // Use the color function
    free(red); // Cleanup memory
}

void bike_color(Vehicle* vehicle) {
    // For this example, we're assuming bikes are blue.
    Blue* blue = (Blue*)malloc(sizeof(Blue));
    blue->base.fill = blue_fill; // Assign color fill behavior
    blue->base.fill(&blue->base); // Use the color function
    free(blue); // Cleanup memory
}

// Abstract Factory Interface
typedef struct AbstractFactory {
    Vehicle* (*create_vehicle)(void);
    void (*apply_color)(Vehicle* vehicle);  // Function to apply color
} AbstractFactory;

// Concrete Factories for Car and Red
Vehicle* create_car() {
    Car* car = (Car*)malloc(sizeof(Car));
    car->base.drive = car_drive;
    car->base.color = car_color;  // Assign color function
    return (Vehicle*)car;
}

// Concrete Factories for Bike and Blue
Vehicle* create_bike() {
    Bike* bike = (Bike*)malloc(sizeof(Bike));
    bike->base.drive = bike_drive;
    bike->base.color = bike_color;  // Assign color function
    return (Vehicle*)bike;
}

// Concrete Factory for Car and Red Color
AbstractFactory* create_car_factory() {
    AbstractFactory* factory = (AbstractFactory*)malloc(sizeof(AbstractFactory));
    factory->create_vehicle = create_car;
    factory->apply_color = car_color;  // Factory for car with color red
    return factory;
}

// Concrete Factory for Bike and Blue Color
AbstractFactory* create_bike_factory() {
    AbstractFactory* factory = (AbstractFactory*)malloc(sizeof(AbstractFactory));
    factory->create_vehicle = create_bike;
    factory->apply_color = bike_color;  // Factory for bike with color blue
    return factory;
}

// Client Code
int main() {
    // Using the Abstract Factory for Car and Red
    AbstractFactory* carFactory = create_car_factory();
    Vehicle* car = carFactory->create_vehicle();
    carFactory->apply_color(car);  // Apply red color to the car
    car->drive(car);  // Output: Driving a car...

    // Using the Abstract Factory for Bike and Blue
    AbstractFactory* bikeFactory = create_bike_factory();
    Vehicle* bike = bikeFactory->create_vehicle();
    bikeFactory->apply_color(bike);  // Apply blue color to the bike
    bike->drive(bike);  // Output: Riding a bike...

    // Free memory
    free(car);
    free(bike);
    free(carFactory);
    free(bikeFactory);

    return 0;
}
