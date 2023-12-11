#include "PmergeMe.hpp"

template <class T>
void print(T &container)
{
    typename T::iterator it;

    for (it = container.begin(); it != container.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::vector<int> vec;
    std::deque<int> deque;
    PmergeMe sorter;

    if (argc < 2)
    {
        std::cout << RED << "Error: No arguments provided." << std::endl << RESET;
        return 1;
    }

    if (!sorter.extractPositiveIntegers(argv + 1, vec, deque))
    {
        std::cout << RED << "Error: Failed to extract positive integers." << std::endl << RESET;
        return 1;
    }

    std::cout << BLUE << "Before: " << RESET;
    print(vec);

    double vecTime = sorter.mergeInsertionSort(vec);
    double dequeTime = sorter.mergeInsertionSort(deque);

    std::cout << BLUE << "After: " << RESET;
    print(vec);

    std::cout << YELLOW << "Time to process a range of " << vec.size() << " elements with std::vector : " << RESET
              << vecTime << " s /"
              << vecTime * 1000 << " ms /"
              << vecTime * 1000 * 1000 << " µs \n";
    std::cout << YELLOW << "Time to process a range of " << deque.size() << " elements with std::deque : " << RESET
              << dequeTime << " s /"
              << dequeTime * 1000 << " ms /"
              << dequeTime * 1000 * 1000 << " µs \n";

    return 0;
}