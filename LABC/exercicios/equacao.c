#include <stdio.h>
#include <math.h>

int eq2grau(float a, float b, float c, float *y1, float *y2) {
    int d = b*b-4*a*c;
    if (d == 0) {
        *y1 = -b/(2*a);
        return 1;
    } 
    else if (d > 0) {
        *y1 = (-b + sqrt(d)) / (2*a);
        *y2 = (-b - sqrt(d)) / (2*a);
        return 2;
    }
    return 0;
}

int main() {
    float a,b,c;
    float x1 = 0.0, x2 = 0.0;

    scanf("%f %f %f",&a, &b, &c);
    switch(eq2grau(a,b,c,&x1,&x2)) {
        case 0:
            printf("N N\n");
            break;
        case 1:
            printf("%.2f N\n", x1);
            break;
        case 2:
            printf("%.2f %.2f\n", x1, x2);
            break;
    }
    return 0;
}
