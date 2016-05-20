#include <iostream>

#define length 5

using namespace std;

void name_swap(string *a, string *b);
void hight_swap(int *a, int *b);

string name[length] = {"Mike", "Amy", "Bob", "Andy", "Mary"};
int hight[length] = {170, 160, 175, 180, 163};

int main()
{
    int num_min;
    //display initial value
    cout<<"=====Before compare====="<<endl;
    for(int i=0; i<length; i++){
        cout<<name[i]<<" "<<hight[i]<<endl;
    }

    for(int i=0; i<length; i++){
        num_min = i;
        //compare
        for(int j=i+1; j<length; j++){
            if(hight[num_min] > hight[j]){
                num_min = j;
            }
        }
        //swap
        if(num_min != i){
            name_swap(name+num_min, name+i);
            hight_swap(hight+num_min, hight+i);
        }
    }

    //display compared value
    cout<<"=====After compare====="<<endl;
    for(int i=0; i<length; i++){
        cout<<name[i]<<" "<<hight[i]<<endl;
    }

    return 0;
}

void name_swap(string *a, string *b){
    string temp = *a;
    *a = *b;
    *b = temp;
}

void hight_swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

