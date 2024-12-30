#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for the Computer
typedef struct {
    char CPU[100];
    char RAM[100];
    char storage[100];
    char GPU[100];
} Computer;

// Function to create a Computer
Computer* create_computer(const char* cpu, const char* ram, const char* storage, const char* gpu) {
    Computer* comp = (Computer*)malloc(sizeof(Computer));
    strncpy(comp->CPU, cpu, sizeof(comp->CPU) - 1);
    strncpy(comp->RAM, ram, sizeof(comp->RAM) - 1);
    strncpy(comp->storage, storage, sizeof(comp->storage) - 1);
    strncpy(comp->GPU, gpu, sizeof(comp->GPU) - 1);
    return comp;
}

int main() {
    // Create a Gaming PC
    Computer* gamingPC = create_computer("Intel i9", "32GB DDR4", "1TB SSD", "NVIDIA RTX 3080");
    printf("Gaming PC: CPU = %s, RAM = %s, Storage = %s, GPU = %s\n", gamingPC->CPU, gamingPC->RAM, gamingPC->storage, gamingPC->GPU);

    // Create an Office PC
    Computer* officePC = create_computer("Intel i5", "8GB DDR4", "500GB SSD", "Integrated GPU");
    printf("Office PC: CPU = %s, RAM = %s, Storage = %s, GPU = %s\n", officePC->CPU, officePC->RAM, officePC->storage, officePC->GPU);

    // Free memory
    free(gamingPC);
    free(officePC);

    return 0;
}
