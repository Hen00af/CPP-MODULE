#include <iostream>
#include "Serializer.hpp"

int main() {
	Data data;
	data.name = "test";
	data.value = 42;

	std::cout << "Original pointer: " << &data << std::endl;
	std::cout << "name: " << data.name << ", value: " << data.value << std::endl;

	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "Serialized: " << raw << std::endl;

	Data *ptr = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << ptr << std::endl;
	std::cout << "name: " << ptr->name << ", value: " << ptr->value << std::endl;

	if (ptr == &data)
		std::cout << "Pointers are equal: OK" << std::endl;
	else
		std::cout << "Pointers are NOT equal: KO" << std::endl;

	return 0;
}
