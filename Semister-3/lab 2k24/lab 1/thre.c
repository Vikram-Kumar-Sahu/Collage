#include <stdio.h>
#include <stdlib.h>
struct Employee {
    int emp_id;
    char name[50];
    char designation[50];
    float basic_salary;
    float hra_percent;
    float da_percent;
    float gross_salary;
};
float calculateGrossSalary(float basic, float hra_percent, float da_percent) {
    return basic + (basic * hra_percent / 100) + (basic * da_percent / 100);
}

int main() {
    int n;
    
    printf("Enter no. of employees: ");
    scanf("%d", &n);
    struct Employee *employees = (struct Employee *)malloc(n * sizeof(struct Employee));
    
    if (employees == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("Enter employee %d information:\n", i + 1);
        printf("Name: ");
        scanf("%s", employees[i].name);
        printf("Designation: ");
        scanf("%s", employees[i].designation);
        printf("Basic Salary: ");
        scanf("%f", &employees[i].basic_salary);
        printf("HRA %%: ");
        scanf("%f", &employees[i].hra_percent);
        printf("DA %%: ");
        scanf("%f", &employees[i].da_percent);
      employees[i].gross_salary = calculateGrossSalary(employees[i].basic_salary, employees[i].hra_percent, employees[i].da_percent);
    }
    printf("\nEmployee Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", employees[i].name);
        printf("Designation: %s\n", employees[i].designation);
        printf("Basic Salary: %.2f\n", employees[i].basic_salary);
        printf("HRA %%: %.2f\n", employees[i].hra_percent);
        printf("DA %%: %.2f\n", employees[i].da_percent);
        printf("Gross Salary: %.2f\n", employees[i].gross_salary);
        printf("\n");
    }
    free(employees);
    return 0;
}