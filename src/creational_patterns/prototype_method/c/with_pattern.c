/*

Prototype Design Pattern in C

The Prototype Design Pattern is a creational pattern that allows creating new objects by copying an existing object (called a prototype). Instead of creating a new instance of an object from scratch, the prototype pattern allows you to clone an existing object and modify its properties as needed. This is useful when the cost of creating an object from scratch is more expensive than copying an existing one, or when the objects are complex to create.

In C, the Prototype pattern can be implemented using structs, function pointers, and a clone function. The clone function allows you to copy an object and then modify it if necessary.
Scenario: Cloning a Car object

We'll create a Car struct with properties like make, model, and year. Then, we'll use the Prototype pattern to clone a car object.

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Abstract Prototype Interface
typedef struct Car {
    char make[50];
    char model[50];
    int year;
    
    // Clone function pointer
    struct Car* (*clone)(struct Car* car);
} Car;

// Clone Function for Car (Creates a deep copy)
Car* car_clone(Car* car) {
    Car* new_car = (Car*)malloc(sizeof(Car));
    if (new_car != NULL) {
        strcpy(new_car->make, car->make);  // Copy the make
        strcpy(new_car->model, car->model);  // Copy the model
        new_car->year = car->year;  // Copy the year
        new_car->clone = car_clone;  // Set the clone function for the new car
    }
    return new_car;
}

// Constructor for Car (Initializes a car)
Car* create_car(const char* make, const char* model, int year) {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car != NULL) {
        strcpy(car->make, make);
        strcpy(car->model, model);
        car->year = year;
        car->clone = car_clone;  // Set the clone function
    }
    return car;
}

// Client Code
int main() {
    // Create an original car object
    Car* original_car = create_car("Toyota", "Corolla", 2020);

    // Clone the original car
    Car* cloned_car = original_car->clone(original_car);

    // Display the details of both cars
    printf("Original Car: %s %s, %d\n", original_car->make, original_car->model, original_car->year);
    printf("Cloned Car: %s %s, %d\n", cloned_car->make, cloned_car->model, cloned_car->year);

    // Modify the cloned car details
    strcpy(cloned_car->make, "Honda");
    strcpy(cloned_car->model, "Civic");
    cloned_car->year = 2022;

    // Display the modified cloned car details
    printf("Modified Cloned Car: %s %s, %d\n", cloned_car->make, cloned_car->model, cloned_car->year);

    // Free memory
    free(original_car);
    free(cloned_car);

    return 0;
}
