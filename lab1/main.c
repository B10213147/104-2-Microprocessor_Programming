#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef struct{
    float real_part;
    float imaginary_part;
    float magnitude;
    float phase;
}complex_num;

int main()
{
    char str[10];
    gets(str);

    char first_flag = false;
    char mid_flag = false;
    char last_flag = false;
    int i = 0;
    char mid_Sign;
    char first_Sign;

    while(str[i] != NULL) i++;

    printf("%d\n",i);

    if(str[i-1] == 'i'){
        last_flag = true;
    }
    else{
        last_flag = false;
    }
    i--;

    while(str[i-1] >= 48 && str[i-1] <= 57){
        i--;
    }

    if(i-1 <= 0){
        mid_flag = false;
        mid_Sign = NULL;
    }
    else{
        mid_flag = true;
        mid_Sign = str[i-1];
    }

    //printf("mid_sign=%c\n", str[i-1]);

    if(str[0] == '-'){   //check first character is negative or not
        first_flag = true;
        first_Sign = str[0];
    }
    else{
        first_flag = false;
        first_Sign = NULL;
    }

    int check = (int)first_flag*100 + (int)mid_flag*10 + (int)last_flag;

    switch(check){
    case 0:
        printf("only real part\n");
        break;
    case 1:
        printf("only imaginary part\n");
        break;
    case 10:
        printf("input type error\n");
        break;
    case 11:
        printf("complex number\n");
        break;
    case 100:
        printf("only real part\n");
        break;
    case 101:
        printf("only imaginary part\n");
        break;
    case 110:
        printf("input type error\n");
        break;
    case 111:
        printf("complex number\n");
        break;
    default:
        printf("ERROR\n");

    }
    printf("check=%d\n",check);

    return 0;
}
