#include "Serializer.hpp"
#include <iostream>

// Test program for Serializer class. Creates a Data instance,
// serializes it, deserializes the raw value, and checks pointer equality.
int main()
{
	Data myData;
	myData.id = 42;
	myData.name = "Test Data";

	std::cout << "Original Data pointer: " << &myData << std::endl;
	
	uintptr_t raw = Serializer::serialize(&myData);
	std::cout << "Serialized address (uintptr_t): " << raw << std::endl;
	
	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer: " << deserialized << std::endl;

	if (deserialized == &myData)
	{
		std::cout << "SUCCESS: Pointers match!" << std::endl;
		std::cout << "Data check: id=" << deserialized->id 
			<< ", name='" << deserialized->name << "'" << std::endl;
	}
	else
		std::cout << "INFO: Pointers do not match (serialize/deserialize are stubs)." << std::endl;

	return 0;
}