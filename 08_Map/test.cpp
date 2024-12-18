#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;

    int number = 42;
    double pi = 3.14159265359;
    std::string text = "Hello, World!";

    // Insert data into the stringstream
    ss << "Number: " << number << ", Pi: " << pi << ", Text: " << text;

    // Extract data from the stringstream
    int extractedNumber;
    double extractedPi;
    std::string extractedText;
    ss >> extractedText >> extractedNumber >> extractedText >> extractedPi >> extractedText >> extractedText;

    std::cout << "Extracted Number: " << extractedNumber << std::endl;
    std::cout << "Extracted Pi: " << extractedPi << std::endl;
    std::cout << "Extracted Text: " << extractedText << std::endl;

    // Get the stringstream contents as a string
    std::string result = ss.str();
    std::cout << "StringStream Contents: " << result << std::endl;

    return 0;
}
