#include <iostream>
#include <cmath> // For round()

// Function to convert Fahrenheit to Celsius
double convertToCelsius(double fahrenheit) {
    return std::round((fahrenheit - 32) * (5.0 / 9.0) * 10) / 10;
}

// Function to convert Celsius to Fahrenheit
double convertToFahrenheit(double celsius) {
    return std::round(((celsius * 9.0) / 5.0 + 32) * 10) / 10;
}

int main() {
    // Example usage
    double fahrenheit = 100.0;
    double celsius = 37.8;

    std::cout << "Fahrenheit to Celsius: " << convertToCelsius(fahrenheit) << "°C\n";
    std::cout << "Celsius to Fahrenheit: " << convertToFahrenheit(celsius) << "°F\n";

    return 0;
}
