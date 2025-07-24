#include <iostream>

bool is_within_limits(float temperature, float soc, float cnn) {
    return (temperature >= 0 && temperature <= 45) &&
           (soc >= 20 && soc <= 80) &&
           (cnn <= 0.8) &&
           (cnn <= 3);  // Added cnn <= 3 condition
}

bool battery_is_ok(float temperature, float soc, float cnn) {
    if (is_within_limits(temperature, soc, cnn)) {
        return true;
    }
    std::cout << "Temperature, State of Charge and Charge Rate is out of range!" << std::endl;
    return false;
}

int main() {
    if (battery_is_ok(25, 70, 0.7)) {
        std::cout << "Battery is OK for (25, 70, 0.7)" << std::endl;
    } else {
        std::cout << "Battery check failed for (25, 70, 0.7)" << std::endl;
    }

    if (!battery_is_ok(50, 85, 0)) {
        std::cout << "Battery check failed as expected for (50, 85, 0)" << std::endl;
    } else {
        std::cout << "Battery is OK for (50, 85, 0), which is unexpected" << std::endl;
    }

    if (!battery_is_ok(30, 50, 3.5)) {
        std::cout << "Battery check failed as expected for cnn > 3 (3.5)" << std::endl;
    } else {
        std::cout << "Battery is OK for cnn > 3, which is unexpected" << std::endl;
    }

    return 0;
}
