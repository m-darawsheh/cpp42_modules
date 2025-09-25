#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
    Data *data = new Data();
    data->num = 42;
    data->sum = "Hello World";
    std::cout << "Data address: " << data << std::endl;
    std::cout << "Data num: " << data->num << std::endl;
    std::cout << "Data sum: " << data->sum << std::endl;

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized data (uintptr_t): " << raw << std::endl;

    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data address: " << deserializedData << std::endl;
    std::cout << "Deserialized Data num: " << deserializedData->num << std::endl;
    std::cout << "Deserialized Data sum: " << deserializedData->sum << std::endl;

    delete data;
    return 0;
}