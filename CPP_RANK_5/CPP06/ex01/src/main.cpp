#include "Serializer.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

int main() 
{
    Data originalData = {"Filipa Borges", 35};

    // Imprime endereço hexadecimal da instância originalData
    std::cout << GREEN << "Hexadecimal Address of originalData: "<< RESET << &originalData << "\n\n";

    // Imprime informações da instância originalData
    std::cout << YELLOW << "Original Data = {name = " << RESET << originalData.name << YELLOW << ", age = " << RESET <<  originalData.age << YELLOW << "}\n\n" << RESET;

    // Serializa o endereço da instância originalData
    uintptr_t serializedAddress = Serializer::serialize(&originalData);
    std::cout << BLUE << "Serialized address of originalData: " << RESET << serializedAddress << "\n\n";

    // Desserializar o endereço serializado para obter uma cópia
    Data *copy = Serializer::deserialize(serializedAddress);
    std::cout << RED << "Deserialized address of originalData: " << RESET << copy << "\n\n";
    std::cout << BLUE << "Copy = {name = " << RESET << copy->name << BLUE << ", age = " << RESET << copy->age << BLUE << "}\n\n" << RESET;

    return 0;
}
