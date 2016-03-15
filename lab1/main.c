#include "stdio.h"
#include "stdlib.h"
#include "math.h"

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

int num2array(float x, int *q_int){
    int i=0;
    int digit;

    x = x*10;   //trick in here
    //cannot determine between the float value
    while(((int)(x*100) <= -10) || ((int)(x*100) >= 10)){
        x = x/10;
        i++;
    }
    digit = i;
    int check;
    //char sign;

    x = x*pow(10,i+2);  //make ii.xxx to iixxx

    while(i>=0){
        check = abs((int)x % 10);
        q_int[i] = check;
        x /= 10;
        i--;
    }

    switch(digit){
    case 2:
        for(i=9; i>0; i--){
            q_int[i] = q_int[i-1];
        }

        q_int[0] = 0;
        digit += 1;
        break;

    case 1:
        for(i=9; i>1; i--){
            q_int[i] = q_int[i-2];
        }

        q_int[0] = 0;
        q_int[1] = 0;
        digit += 2;
        break;

    case 0:
        for(i=9; i>2; i--){
            q_int[i] = q_int[i-3];
        }

        q_int[0] = 0;
        q_int[1] = 0;
        q_int[2] = 0;
        digit += 3;
        break;

    default:

        break;
    }

    return digit;
}

char int2char(int x){
    if((x>=0 && x<=9) || x==-2){
        x = x+48;
    }
    else{
        printf("Convert value is not 0~9 or dot.\n");
        printf("Error num=%d\n",x);
        system("pause");
    }
    return (char)x;
}

void print_String(int *a, int size){
    int i;
    char temp;
    char *out = malloc(size+1);

    for(i=0;i<size;i++){
        temp = int2char(a[i]);
        out[i] = 0;
        out[i] = temp;
    }
    out[size] = '\0';   //add '\0' at last to complete the string format

    printf("%s",out);

    free(out);
}

void adjust_Float(int *a, int digit){
    int d2flag, d1flag;

    if(a[digit-1] == 0) d2flag = 0;
    else d2flag = 1;

    if(a[digit-2] == 0) d1flag = 0;
    else d1flag = 1;

    int check = 10*d1flag + d2flag;

    switch(check){
    case 0:
        //printf("only decimal\n");

        print_String(a, digit-2);
        break;

    case 1:
        //printf("float to 2 part\n");

        //shift and add dot
        a[digit] = a[digit-1];
        a[digit-1] = a[digit-2];
        a[digit-2] = -2;

        print_String(a, digit+1);
        break;

    case 10:
        //printf("float to 1 part\n");

        //shift and add dot
        a[digit-1] = a[digit-2];
        a[digit-2] = -2;

        print_String(a, digit);
        break;

    case 11:
        //printf("float to 2 part\n");

        //shift and add dot
        a[digit] = a[digit-1];
        a[digit-1] = a[digit-2];
        a[digit-2] = -2;

        print_String(a, digit+1);
        break;

    default:
        printf("Error in adjust_Float()!\n");
    }
}

void print_Complex(complex_num num){
    int *a = malloc(20);
    int format1,format2,check;

    if((int)(num.real_part*1000)==0) format1 = 0;
    else format1 = 1;
    if((int)(num.imaginary_part*1000)==0) format2 = 0;
    else format2 = 1;

    check = 10*format2 + format1;
    //printf("check=%d\n",check);
    switch(check){
    case 0: //0+0i
        printf("0");
        break;

    case 1: //only real part
        if((int)num.real_part<0) printf("-");

        adjust_Float(a,num2array(num.real_part,a));
        break;

    case 10:    //only imaginary part
        if((int)num.imaginary_part<0) printf("-");

        adjust_Float(a,num2array(num.imaginary_part,a));

        printf("i");
        break;

    case 11:    //complex number
        if((int)(num.real_part*10)<0) printf("-");

        adjust_Float(a,num2array(num.real_part,a));

        if((int)(num.imaginary_part*10)<0) printf("-");
        else printf("+");

        adjust_Float(a,num2array(num.imaginary_part,a));

        printf("i");
        break;

    default:
        printf("Error in print_Complex()!\n");
    }

    printf("\n");

    free(a);
}

int main()
{
    complex_num a = get_Complex();

    //a.real_part = 0.911;
    //a.imaginary_part = 1.101;

    print_Complex(a);

    return 0;
}
