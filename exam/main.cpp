#include <iostream>

#define length 5

using namespace std;

struct student{
    string name;
    int hight;
};

void name_swap(struct student *a, struct student *b);

struct student class_A[length] = {
    {"Mike", 170},
    {"Amy", 160},
    {"Bob", 175},
    {"Andy", 180},
    {"Mary", 163}
};

int main()
{
    int num_min;
    //display initial value
    cout<<"=====Before compare====="<<endl;
    for(int i=0; i<length; i++){
        cout<<class_A[i].name<<" "<<class_A[i].hight<<endl;
    }

    for(int i=0; i<length; i++){
        num_min = i;
        //compare
        for(int j=i+1; j<length; j++){
            if(class_A[num_min].hight > class_A[j].hight){
                num_min = j;
            }
        }
        //swap
        if(num_min != i){
            name_swap(class_A+num_min, class_A+i);
        }
    }

    //display compared value
    cout<<"=====After compare====="<<endl;
    for(int i=0; i<length; i++){
        cout<<class_A[i].name<<" "<<class_A[i].hight<<endl;
    }

    return 0;
}

void name_swap(struct student *a, struct student *b){
    struct student temp = *a;
    *a = *b;
    *b = temp;
}

