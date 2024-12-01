#include <stdio.h>

// Define a struct to hold currency conversion rates
struct ConversionRate {
    char currency[4]; // Currency code (e.g., USD, MYR, SGD, IDR, PHP)
    float rate;       // Conversion rate
};

// Function to convert USD to other currencies
float convert(float usd, struct ConversionRate *conversion) {
    return usd * conversion->rate;
}

int main() {
    // Define conversion rates for different currencies
    struct ConversionRate rates[] = {
        {"MYR", 4.15},
        {"SGD", 1.36},
        {"IDR", 14698.5},
        {"PHP", 48.58}
    };

    // Prompt the user to select a currency conversion
    printf("Select currency conversion:\n");
    printf("1. USD to MYR (Malaysian ringgit)\n");
    printf("2. USD to SGD (Singaporean dollar)\n");
    printf("3. USD to IDR (Indonesian rupiah)\n");
    printf("4. USD to PHP (Philippine peso)\n");
    printf("Enter your choice (1-4): ");

    int choice;
    scanf("%d", &choice);

    // Check if the choice is within range
    if (choice < 1 || choice > 4) {
        printf("Invalid choice\n");
        return 1; // Exit with error
    }

    // Prompt the user to enter the USD value
    float usd;
    printf("Enter the USD value: ");
    scanf("%f", &usd);

    // Convert USD to the selected currency
    float converted_value = convert(usd, &rates[choice - 1]);

    // Display the result
    printf("Converted value: %s %.2f \n", rates[choice - 1].currency, converted_value);

    return 0;
}