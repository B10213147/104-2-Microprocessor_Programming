#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define false 0
#define true 1
#define empty -1

typedef struct{
    float real_part;
    float imaginary_part;
    float magnitude;
    float phase;
}complex_num;

int char2int(char in){
    int out = in - 48;
    printf("out=%d\n",out);
    return out;
}

complex_num get_Complex(void){
    complex_num temp;
    char str[10];
    gets(str);

    char first_flag = false;
    char mid_flag = false;
    char last_flag = false;
    int i = 0;
    char mid_Sign;
    char first_Sign;
    int last_Sign_bit;
    int mid_Sign_bit;

    while(str[i] != 0) i++;  //total bits of input string

    printf("%d\n",i);

    if(str[i-1] == 'i'){    //find the last bit is 'i' or not
        last_flag = true;
    }
    else{
        last_flag = false;
    }
    last_Sign_bit = i-1;
    i--;

    //find mid_sign is at which bit
    while(str[i-1] >= 48 && str[i-1] <= 57){
        i--;
    }

    if(i-1 <= 0){   //check mid_flag is not at the first bit
        mid_flag = false;
        mid_Sign = empty;
        mid_Sign_bit = empty;
    }
    else{
        mid_flag = true;
        mid_Sign = str[i-1];
        mid_Sign_bit = i-1;
    }

    if(str[0] == '-'){   //check first character is negative or not
        first_flag = true;
        first_Sign = str[0];
    }
    else{
        first_flag = false;
        first_Sign = empty;
    }

    int check = (int)first_flag*100 + (int)mid_flag*10 + (int)last_flag;
    float sum = 0;
    int j;

    switch(check){
    case 0:
        printf("only real part\n");
        int n = 0;
        for(j=last_Sign_bit; j>=0; j--){
            sum = sum + char2int(str[j]) * pow(10,n);
            printf("sum=%f\n",sum);
            n++;
        }
        temp.real_part = sum;
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
    return temp;
}

int main()
{
    complex_num a, b;
    a = get_Complex();
    printf("real_part=%d\n",(int)a.real_part);
    //b = get_Complex();
    //printf("real_part=%d\n",b.real_part);

    return 0;
}
