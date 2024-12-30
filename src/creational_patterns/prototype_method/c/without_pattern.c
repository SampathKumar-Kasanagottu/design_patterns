#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Car struct without Prototype Pattern
typedef struct Car {
    char make[50];
    char model[50];
    int year;
} Car;

// Constructor for Car (Initializes a car)
Car* create_car(const char* make, const char* model, int year) {
    Car* car = (Car*)malloc(sizeof(Car));
    if (car != NULL) {
        strcpy(car->make, make);
        strcpy(car->model, model);
        car->year = year;
    }
    return car;
}

// Client Code
int main() {
    // Create an original car object
    Car* original_car = create_car("Toyota", "Corolla", 2020);

    // Directly create a new car (without cloning)
    Car* cloned_car = create_car("Toyota", "Corolla", 2020);

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
