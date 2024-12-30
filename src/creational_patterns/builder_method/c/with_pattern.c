#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Product: Computer
typedef struct {
    char CPU[100];
    char RAM[100];
    char storage[100];
    char GPU[100];
} Computer;

// Builder Interface
typedef struct ComputerBuilder {
    Computer* computer;  // Pointer to the Computer being built
    void (*setCPU)(struct ComputerBuilder*, const char*);
    void (*setRAM)(struct ComputerBuilder*, const char*);
    void (*setStorage)(struct ComputerBuilder*, const char*);
    void (*setGPU)(struct ComputerBuilder*, const char*);
    Computer* (*build)(struct ComputerBuilder*);
} ComputerBuilder;

// Function prototypes for setting parts
void setCPU(ComputerBuilder* builder, const char* cpu);
void setRAM(ComputerBuilder* builder, const char* ram);
void setStorage(ComputerBuilder* builder, const char* storage);
void setGPU(ComputerBuilder* builder, const char* gpu);
Computer* build(ComputerBuilder* builder);

// Concrete Builder for building a Computer
void setCPU(ComputerBuilder* builder, const char* cpu) {
    strncpy(builder->computer->CPU, cpu, sizeof(builder->computer->CPU) - 1);
}

void setRAM(ComputerBuilder* builder, const char* ram) {
    strncpy(builder->computer->RAM, ram, sizeof(builder->computer->RAM) - 1);
}

void setStorage(ComputerBuilder* builder, const char* storage) {
    strncpy(builder->computer->storage, storage, sizeof(builder->computer->storage) - 1);
}

void setGPU(ComputerBuilder* builder, const char* gpu) {
    strncpy(builder->computer->GPU, gpu, sizeof(builder->computer->GPU) - 1);
}

Computer* build(ComputerBuilder* builder) {
    return builder->computer;
}

// Director that constructs the object
typedef struct {
    ComputerBuilder* builder;
} Director;

void constructGamingPC(Director* director) {
    director->builder->setCPU(director->builder, "Intel i9");
    director->builder->setRAM(director->builder, "32GB DDR4");
    director->builder->setStorage(director->builder, "1TB SSD");
    director->builder->setGPU(director->builder, "NVIDIA RTX 3080");
}

void constructOfficePC(Director* director) {
    director->builder->setCPU(director->builder, "Intel i5");
    director->builder->setRAM(director->builder, "8GB DDR4");
    director->builder->setStorage(director->builder, "500GB SSD");
    director->builder->setGPU(director->builder, "Integrated GPU");
}

int main() {
    // Create a builder
    ComputerBuilder builder = {
        .computer = (Computer*)malloc(sizeof(Computer)),
        .setCPU = setCPU,
        .setRAM = setRAM,
        .setStorage = setStorage,
        .setGPU = setGPU,
        .build = build
    };

    // Create a director for constructing objects
    Director director = {.builder = &builder};

    // Construct a gaming PC
    constructGamingPC(&director);
    Computer* gamingPC = builder.build(&builder);
    printf("Gaming PC: CPU = %s, RAM = %s, Storage = %s, GPU = %s\n", gamingPC->CPU, gamingPC->RAM, gamingPC->storage, gamingPC->GPU);

    // Reset the builder and construct an office PC
    builder.computer = (Computer*)malloc(sizeof(Computer));
    constructOfficePC(&director);
    Computer* officePC = builder.build(&builder);
    printf("Office PC: CPU = %s, RAM = %s, Storage = %s, GPU = %s\n", officePC->CPU, officePC->RAM, officePC->storage, officePC->GPU);

    // Free memory
    free(gamingPC);
    free(officePC);

    return 0;
}
