#include <stdio.h>

void convertLength() {
    int choice;
    float value, converted_value;

    printf("Length Conversion:\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    if (choice == 1) {
        converted_value = value / 1000; // Meters to Kilometers
        printf("%.2f meters is equal to %.2f kilometers.\n", value, converted_value);
    } else if (choice == 2) {
        converted_value = value * 1000; // Kilometers to Meters
        printf("%.2f kilometers is equal to %.2f meters.\n", value, converted_value);
    } else {
        printf("Invalid choice!\n");
    }
}

void convertMass() {
    int choice;
    float value, converted_value;

    printf("Mass Conversion:\n");
    printf("1. Grams to Kilograms\n");
    printf("2. Kilograms to Grams\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter the value to convert: ");
    scanf("%f", &value);

    if (choice == 1) {
        converted_value = value / 1000; // Grams to Kilograms
        printf("%.2f grams is equal to %.2f kilograms.\n", value, converted_value);
    } else if (choice == 2) {
        converted_value = value * 1000; // Kilograms to Grams
        printf("%.2f kilograms is equal to %.2f grams.\n", value, converted_value);
    } else {
        printf("Invalid choice!\n");
    }
}

int main() {
    int category_choice;

    printf("Welcome to the Unit Converter!\n");
    printf("Choose the type of conversion:\n");
    printf("1. Length (e.g., meters to kilometers)\n");
    printf("2. Mass (e.g., grams to kilograms)\n");
    printf("Enter your choice: ");
    scanf("%d", &category_choice);

    switch (category_choice) {
        case 1:
            convertLength();
            break;
        case 2:
            convertMass();
            break;
        default:
            printf("Invalid conversion category!\n");
    }

    return 0;
}
