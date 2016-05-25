#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "string.h"

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
    return out;
}

complex_num get_Complex(void){
    complex_num temp;
    char str[20];
    char first_flag = false;
    char mid_flag = false;
    char last_flag = false;
    char mid_Sign, first_Sign;
    int last_Sign_bit, mid_Sign_bit;

    gets(str);
    int i = strlen(str);    //total bits of input string

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

    if(str[0] == '-' || str[0] == '+'){   //check first character
        first_flag = true;
        first_Sign = str[0];
    }
    else{
        first_flag = false;
        first_Sign = empty;
    }

    int check = (int)first_flag*100 + (int)mid_flag*10 + (int)last_flag;
    int sum = 0;
    int j;
    int n = 0;

    switch(check){
    case 0:
        //printf("only real part\n");

        for(j=last_Sign_bit; j>=0; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        temp.real_part = (float)sum;
        temp.imaginary_part = 0;
        break;

    case 1:
        //printf("only imaginary part\n");

        for(j=last_Sign_bit-1; j>=0; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        temp.real_part = 0;
        temp.imaginary_part = (float)sum;
        break;

    case 10:
        //printf("input type error\n");

        temp.real_part = 0;
        temp.imaginary_part = 0;
        break;

    case 11:
        //printf("complex number\n");

        for(j=last_Sign_bit-1; j>mid_Sign_bit; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        if(mid_Sign == '-') temp.imaginary_part = (float)(-sum);
        else if(mid_Sign == '+') temp.imaginary_part = (float)sum;

        sum = 0;
        n = 0;

        for(j=mid_Sign_bit-1; j>=0; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        temp.real_part = (float)sum;
        break;

    case 100:
        //printf("only real part\n");

        for(j=last_Sign_bit; j>=1; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        if(first_Sign == '-') temp.real_part = (float)(-sum);
        else if(first_Sign == '+') temp.real_part = (float)sum;

        temp.imaginary_part = 0;
        break;

    case 101:
        //printf("only imaginary part\n");

        for(j=last_Sign_bit-1; j>=1; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        temp.real_part = 0;
        temp.imaginary_part = (float)(-sum);
        break;

    case 110:
        //printf("input type error\n");

        temp.real_part = 0;
        temp.imaginary_part = 0;
        break;

    case 111:
        //printf("complex number\n");

        for(j=last_Sign_bit-1; j>mid_Sign_bit; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        if(mid_Sign == '-') temp.imaginary_part = (float)(-sum);
        else if(mid_Sign == '+') temp.imaginary_part = (float)sum;

        sum = 0;
        n = 0;

        for(j=mid_Sign_bit-1; j>=1; j--){
            sum = sum + char2int(str[j]) * (int)pow(10,n);
            n++;
        }

        if(first_Sign == '-') temp.real_part = (float)(-sum);
        else if(first_Sign == '+') temp.real_part = (float)sum;

        break;

    default:
        printf("Error in get_Complex()!\n");
    }

    return temp;
}

complex_num c_Add(complex_num a, complex_num b){
    complex_num answer;

    answer.real_part = a.real_part + b.real_part;
    answer.imaginary_part = a.imaginary_part + b.imaginary_part;

    return answer;
}

complex_num c_Subtract(complex_num a, complex_num b){
    complex_num answer;

    answer.real_part = a.real_part - b.real_part;
    answer.imaginary_part = a.imaginary_part - b.imaginary_part;

    return answer;
}

complex_num c_Product(complex_num a, complex_num b){
    complex_num answer;

    answer.real_part = a.real_part * b.real_part - a.imaginary_part * b.imaginary_part;
    answer.imaginary_part = a.real_part * b.imaginary_part + a.imaginary_part * b.real_part;

    return answer;
}

complex_num c_Divide(complex_num a, complex_num b){
    complex_num answer, fractions, numerator, b_Conjugate;
    //numerator cannot be 0
    if(b.real_part == 0 && b.imaginary_part == 0){
        answer.real_part = 0;
        answer.imaginary_part = 0;
        return answer;
    }

    b_Conjugate.real_part = b.real_part;
    b_Conjugate.imaginary_part = -b.imaginary_part;

    fractions = c_Product(a,b_Conjugate);

    numerator = c_Product(b,b_Conjugate);

    answer.real_part = fractions.real_part/numerator.real_part;
    answer.imaginary_part = fractions.imaginary_part/numerator.real_part;

    return answer;
}

int main()
{
    complex_num answer;

    printf("Enter first complex number:");
    complex_num a = get_Complex();
    printf("Enter second complex number:");
    complex_num b = get_Complex();

    printf("Sum:");
    answer = c_Add(a,b);
    printf("% 2d%+di\n",(int)answer.real_part,(int)answer.imaginary_part);

    printf("Difference:");
    answer = c_Subtract(a,b);
    printf("% 2d%+di\n",(int)answer.real_part,(int)answer.imaginary_part);

    printf("Product:");
    answer = c_Product(a,b);
    printf("% 2d%+di\n",(int)answer.real_part,(int)answer.imaginary_part);

    printf("Quotient:");
    answer = c_Divide(a,b);
    printf("% .2f%+.2fi\n",answer.real_part,answer.imaginary_part);

    system("pause");
    return 0;
}
