#include<stdio.h>

int main(){
    int a =7;
    int b =3;
    scanf("%d", &a);
    scanf("%d", &b); 

    printf("Simple calculator:");
    printf("\n------------------\n");
    printf("\n1st operand: %d\n", a);
    printf("\n2nd operand: %d\n", b);
    printf("\n\n");
    printf("%d + %d = %d\n", a, b, a+b);
    printf("%d - %d = %d\n", a, b, a-b);
    printf("%d * %d = %d\n", a, b, a*b);
    printf("%d / %d = %d\n", a, b, a/b);
    printf("%d %% %d = %d\n", a, b, a%b);

    return 0;

}