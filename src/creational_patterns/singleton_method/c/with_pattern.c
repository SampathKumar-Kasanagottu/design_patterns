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
