#include <stdio.h>

#define MAX 100

void readPolynomial(int poly[MAX], int degree) {
    printf("Enter the coefficients for the polynomial:\n");
    for (int i = degree; i >= 0; i--) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

void printPolynomial(int poly[MAX], int degree) {
    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {
            printf("%d", poly[i]);
            if (i != 0)
                printf("x^%d", i);
            if (i > 0 && poly[i - 1] >= 0)
                printf(" + ");
        }
    }
    printf("\n");
}

void addPolynomials(int poly1[MAX], int poly2[MAX], int result[MAX], int degree1, int degree2) {
    int maxDegree = (degree1 > degree2) ? degree1 : degree2;

    for (int i = 0; i <= maxDegree; i++) {
        if (i <= degree1 && i <= degree2)
            result[i] = poly1[i] + poly2[i];
        else if (i <= degree1)
            result[i] = poly1[i];
        else
            result[i] = poly2[i];
    }
}

int main() {
    int poly1[MAX] = {0}, poly2[MAX] = {0}, result[MAX] = {0};
    int degree1, degree2;

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    readPolynomial(poly1, degree1);

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    readPolynomial(poly2, degree2);

    int maxDegree = (degree1 > degree2) ? degree1 : degree2;
    addPolynomials(poly1, poly2, result, degree1, degree2);

    printf("Resultant polynomial after addition is:\n");
    printPolynomial(result, maxDegree);

    return 0;
}
