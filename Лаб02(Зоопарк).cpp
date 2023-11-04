#include <iostream>
#include <vector>
#include <string>

class Animal {
private:
	std::string name;
public:
	Animal(const std::string& name) : name(name) {}
	std::string getName() const {
		return name;
	}
	virtual void feed() const {
		std::cout << name << " is eating; The animal is well-fed\n";
	}
	virtual void pet() const {
		std::cout << name << " is being stroked; The animal is happy\n";
	}
	virtual void kiss() const {
		std::cout << name << " is being kissed; The animal is satisfied\n";
	}
	virtual void hold() const {
		std::cout << name << " is being held; The animal is satisfied\n";
	}
	virtual void praise() const {
		std::cout << name << " is being praised; The animal is happy\n";
	}
};

class Zoo {
private:
	std::vector<Animal*> animals;
public:
	void addAnimal(Animal* animal) {
		animals.push_back(animal);
	}
	void removeAnimal(const std::string& name) {
		for (auto it = animals.begin(); it != animals.end(); ++it) {
			if ((*it)->getName() == name) {
				animals.erase(it);
				break;
			}
		}
	}
	void printAnimalList() const {
		std::cout << "Welcome to the zoo\n";
		std::cout << "Animals in the zoo:\n";
		for (const auto& animal : animals) {
			std::cout << "- " << animal->getName() << "\n";
		}
	}
	Animal* findAnimal(const std::string& name) const {
		for (const auto& animal : animals) {
			if (animal->getName() == name) {
				return animal;
			}
		}
		return nullptr;
	}
};

int main() {
	Zoo zoo;

	// Создание и добавление животных в зоопарк
	Animal lion("Lion");
	Animal elephant("Elephant");
	Animal parrot("Parrot");
	zoo.addAnimal(&lion);
	zoo.addAnimal(&elephant);
	zoo.addAnimal(&parrot);

	std::string animalName;
	std::string command;

	while (true) {
		zoo.printAnimalList();
		std::cout << "Enter the name of the animal or type 'exit' to quit: ";
		std::cin >> animalName;

		if (animalName == "exit") {
			break;
		}

		Animal* animal = zoo.findAnimal(animalName);
		if (animal == nullptr) {
			std::cout << "Animal not found\n";
			continue;
		}

		std::cout << "What command do you want to use: feed, stroke, kiss, hold, praise, remove\n";
		std::cout << "Enter a command for the animal: ";
		std::cin >> command;

		if (command == "feed") {
			animal->feed();
		}
		else if (command == "stroke") {
			animal->pet();
		}
		else if (command == "kiss") {
			animal->kiss();
		}
		else if (command == "hold") {
			animal->hold();
		}
		else if (command == "praise") {
			animal->praise();
		}
		else if (command == "remove") {
			zoo.removeAnimal(animalName);
		}
		else {
			std::cout << "Invalid command\n";
		}

		std::cout << "----------------------------------------------\n";
	}

	return 0;
}