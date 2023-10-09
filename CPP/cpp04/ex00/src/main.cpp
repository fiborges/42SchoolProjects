#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void test_wrong_inheritance(void)
{
	std::cout << "\n\t=== Testing wrong inheritance of an animal ===\n" << std::endl;
	
	const WrongAnimal *cat = new WrongCat();

	cat->makeSound();
	delete cat;
}

void test_animal_copy(void)
{	
	std::cout << "\n\t=== Testing a copy of an animal ===\n" << std::endl;
	
	const Animal *dog = new Dog();
	const Animal *copy = dog;

	std::cout << copy->getType() << std::endl;
	copy->makeSound();

	const Dog *first = new Dog();
	const Dog *second = new Dog(*first);

	std::cout << first->getType() << std::endl;
	first->makeSound();

	std::cout << second->getType() << std::endl;
	second->makeSound();

	delete dog;
	delete first;
	delete second;
}

void test_inheritance(void)
{
	std::cout << "\n\t=== Testing new animals growls ===\n" << std::endl;
	
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;
}

void test_animal_instance(void)
{
	std::cout << "\n\t=== Testing default animal types ===\n" << std::endl;
	
	const Animal *meta = new Animal();

	meta->makeSound();
	delete meta;
}

int main(void)
{
	test_animal_instance();
	test_inheritance();
	test_animal_copy();
	test_wrong_inheritance();
}

