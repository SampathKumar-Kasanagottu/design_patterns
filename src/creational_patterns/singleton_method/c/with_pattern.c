/*
The Singleton Design Pattern ensures that a class has only one instance and provides a global point of access to that instance. 
This pattern is often used when you need to control access to shared resources, such as a configuration object, logging system, 
or database connection.

In C, the Singleton pattern can be implemented by making the constructor of a structure private and exposing a function that 
manages the unique instance of the structure.

*/

#include <stdio.h>
#include <stdlib.h>

// Singleton Class
typedef struct {
    int value;  // Example data in the Singleton
} Singleton;

// Static instance of the Singleton
static Singleton* instance = NULL;

// Function to get the single instance of Singleton
Singleton* get_instance() {
    if (instance == NULL) {
        instance = (Singleton*)malloc(sizeof(Singleton));
        instance->value = 0;  // Initialize the value to 0
        printf("Creating Singleton instance...\n");
    }
    return instance;
}

// Function to set the value of the Singleton
void set_value(int new_value) {
    Singleton* singleton = get_instance();  // Ensure the instance exists
    singleton->value = new_value;
}

// Function to get the value from the Singleton
int get_value() {
    Singleton* singleton = get_instance();  // Ensure the instance exists
    return singleton->value;
}

// Client Code
int main() {
    // Get the Singleton instance and set a value
    set_value(42);
    printf("Singleton Value: %d\n", get_value());  // Output: Singleton Value: 42

    // Try to get another instance and check if it's the same
    Singleton* s2 = get_instance();
    printf("Singleton Value (from second instance): %d\n", s2->value);  // Output: Singleton Value: 42

    // Verify both instances are the same
    if (get_instance() == s2) {
        printf("Both instances are the same!\n");  // This should print
    }

    // Clean up
    free(s2);

    return 0;
}
