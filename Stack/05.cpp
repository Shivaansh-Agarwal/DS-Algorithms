// Implementation of 2 Stacks in an Array
#include<iostream>
#include<cstdlib>// For exit(0) to Work
using namespace std;

int arr[10];
int top1 = -1, top2 = sizeof(arr)/sizeof(int);

bool canElementBeInserted1(){
    if((top1+1)<top2 && (top1+1)<sizeof(arr)/sizeof(int))
        return true;
    else
        return false;
}

void push1(int elem){
    top1++;
    arr[top1] = elem;
}

void pop1(){
    if(top1==-1)
        cout<<"No Element present in Stack1 (UNDERFLOW)"<<endl;
    else{
        cout<<"Element popped = "<<arr[top1]<<endl;
        top1--;
    }
}

bool canElementBeInserted2(){
    if((top2-1)>top1 && (top2-1)>=0)
        return true;
    else
        return false;
}

void push2(int elem){
    top2--;
    arr[top2] = elem;
}

void pop2(){
    if(top2==sizeof(arr)/sizeof(int))
        cout<<"No Element present in Stack2 (UNDERFLOW)"<<endl;
    else{
        cout<<"Element popped = "<<arr[top2]<<endl;
        top2++;
    }
}

int main(){
    int elem;
    
    int choice;
    while(true){
        cout<<"1. Push Element in Stack 1"<<endl;
        cout<<"2. Pop Element from Stack 1"<<endl;
        cout<<"3. Get top of Stack 1"<<endl;
        cout<<"4. Push Element in Stack 2"<<endl;
        cout<<"5. Pop Element from Stack 2"<<endl;
        cout<<"6. Get top of Stack 2"<<endl;
        cout<<"7. EXIT"<<endl;
        cin>>choice;
        switch(choice){
            case 1:
                if(canElementBeInserted1()){
                    cout<<"Enter the element to be inserted: ";
                    cin>>elem;
                    push1(elem);
                }
                else{
                    cout<<"Element cannot be inserted STACK OVERFLOW may occur"<<endl;
                }
                break;
            case 2:
                pop1();
                break;
            case 3:
                if(top1!=-1)
                    cout<<"Top Element of Stack 1: "<<arr[top1]<<endl;
                else
                    cout<<"Stack 2 is Empty"<<endl;
                break;
            case 4:
                if(canElementBeInserted2()){
                    cout<<"Enter the element to be inserted: ";
                    cin>>elem;
                    push2(elem);
                }
                else{
                    cout<<"Element cannot be inserted, STACK OVERFLOW may occur"<<endl;
                }
                break;
            case 5:
                pop2();
                break;
            case 6:
                if(top2!=sizeof(arr)/sizeof(int))
                    cout<<"Top Element of Stack 2 is: "<<arr[top2]<<endl;
                else
                    cout<<"Stack 2 is Empty"<<endl;
                break;
            case 7:
                exit(0);
        }
    }
}