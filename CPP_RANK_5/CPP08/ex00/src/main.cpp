#include "easyfind.hpp"

template <typename T>
void testContainerFind(T& container, const std::string& name, int tofind)
{
    try
    {
        std::cout << GREEN << "\n\t 0.0.0.0.0.0.0.0.0 TESTING " + name + " 0.0.0.0.0.0.0.0 \n\n" << RESET;

        container.push_back(91);
        container.push_back(42);
        container.push_back(32768);
        container.push_back(std::numeric_limits<int>::max());
        container.push_back(-3);

        int pos = easyfind(container, tofind);        
        std::cout << "Found " << tofind << " in " << name + "[" << pos << "]\n";
    }
    catch(const std::exception& e)
    {
        std::cout << RED << "Couldn't find " << tofind << " in " << name << "\n" << RESET;
    }
}

int main(void)
{
    // Testa diferentes tipos de contêiner
    std::vector<int> vectorContainer;
    std::list<int> listContainer;
    std::deque<int> dequeContainer;

    // Testa para encontrar o valor 91 nos contêiner
    testContainerFind(vectorContainer, "Vector", 91);
    testContainerFind(listContainer, "List", 91);
    testContainerFind(dequeContainer, "Deque", 91);

    // Testa para encontrar o valor 42 nos contêiner
    testContainerFind(vectorContainer, "Vector", 42);
    testContainerFind(listContainer, "List", 42);
    testContainerFind(dequeContainer, "Deque", 42);

    // Testa para encontrar o valor -3 nos contêiner
    testContainerFind(vectorContainer, "Vector", -3);
    testContainerFind(listContainer, "List", -3);
    testContainerFind(dequeContainer, "Deque", -3);

    // Testa para encontrar o valor 100 nos contêiner
    testContainerFind(vectorContainer, "Vector", 100);
    testContainerFind(listContainer, "List", 100);
    testContainerFind(dequeContainer, "Deque", 100);

    return 0;
}



