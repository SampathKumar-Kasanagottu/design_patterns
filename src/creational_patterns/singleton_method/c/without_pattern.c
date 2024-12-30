#include <stdio.h>
#include <stdlib.h>

// Structure for the "Singleton"
typedef struct {
    int value;
} Singleton;

// Function to create and initialize a new Singleton instance
Singleton* create_instance() {
    Singleton* instance = (Singleton*)malloc(sizeof(Singleton));
    instance->value = 0;  // Initialize the value to 0
    return instance;
}

// Function to set the value of the Singleton
void set_value(Singleton* singleton, int new_value) {
    singleton->value = new_value;
}

// Function to get the value from the Singleton
int get_value(Singleton* singleton) {
    return singleton->value;
}

// Client Code
int main() {
    // Create two separate instances of Singleton
    Singleton* s1 = create_instance();
    Singleton* s2 = create_instance();

    // Set values for both instances
    set_value(s1, 42);
    set_value(s2, 100);

    printf("s1 Value: %d\n", get_value(s1));  // Output: s1 Value: 42
    printf("s2 Value: %d\n", get_value(s2));  // Output: s2 Value: 100

    // These two instances are different, so their values will be different
    if (s1 != s2) {
        printf("s1 and s2 are different instances!\n");  // This should print
    }

    // Clean up
    free(s1);
    free(s2);

    return 0;
}
