#include <stdio.h>
#include <string.h>
#include <math.h>

// Define a structure for storing shape parameters
struct Shape {
    char name[20];
    double base;
    double height;
    double side;
    double radius;
};

// Function prototypes
double triangle(struct Shape *s);
double rectangle(struct Shape *s);
double square(struct Shape *s);
double circle(struct Shape *s);

int main() {
    struct Shape shape;
    double area;
    int choice;

    printf("Select a shape:\n");
    printf("1. Triangle\n");
    printf("2. Rectangle\n");
    printf("3. Square\n");
    printf("4. Circle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
        	printf("Enter base of the triangle: ");
            scanf("%lf", &shape.base);
            printf("Enter height of the triangle: ");
            scanf("%lf", &shape.height);
            area = triangle(&shape);
            break;
        case 2:
        	printf("Enter length of the rectangle: ");
            scanf("%lf", &shape.base);
            printf("Enter width of the rectangle: ");
            scanf("%%lf", &shape.height);
            area = rectangle(&shape);
            break;
        case 3:
            printf("Enter the side length of the square: ");
            scanf("%lf", &shape.side);
            area = square(&shape);
            break;
        case 4:
            printf("Enter the radius of the circle: ");
            scanf("%lf", &shape.radius);
            area = circle(&shape);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    printf("Area of %s is: %.2lf\n", shape.name, area);

    return 0;
}

double triangle(struct Shape *s) {
    strcpy(s->name, "Triangle");
    return 0.5 * s->base * s->height;
}

double rectangle(struct Shape *s) {
    strcpy(s->name, "Rectangle");
    return s->base * s->height;
}

double square(struct Shape *s) {
    strcpy(s->name, "Square");
    return s->side * s->side;
}

double circle(struct Shape *s) {
    strcpy(s->name, "Circle");
    return M_PI * s->radius * s->radius;
}