#include <stdio.h>
struct Complex {
    float real;
    float imag;
};
struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}
void multiplyComplex(struct Complex *c1, struct Complex *c2, struct Complex *result) {
    result->real = c1->real * c2->real - c1->imag * c2->imag;
    result->imag = c1->real * c2->imag + c1->imag * c2->real;
}

int main() {
    struct Complex c1, c2, result;
    int choice;

    printf("Enter complex number 1 (real and imaginary): ");
    scanf("%f %f", &c1.real, &c1.imag);

    printf("Enter complex number 2 (real and imaginary): ");
    scanf("%f %f", &c2.real, &c2.imag);

    do {
        printf("MENU\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                result = addComplex(c1, c2);
                printf("Sum = %.2f + %.2fi\n", result.real, result.imag);
                break;
            case 2:
                multiplyComplex(&c1, &c2, &result);
                printf("Product = %.2f + %.2fi\n", result.real, result.imag);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}