//
//  main.cpp
//  CppRevision
//
//  Created by Nishat on 2/9/24.
//
/*
 int 4 bytes -2b 2b(2**31) with one bit for sign
 unsigned int 4b (2**32)
 char: numbers(the ascii value) or characters
 short 2 bytes
 long 4 bytes
 long long
 float 4 bytes
 double 8 bytes
 
 bool 1 byte. 1 or 0 as output, there's no way to access 1 bit, only bytes
 we can store 8 bits in 1 bool
 
 sizeof: gives memory size of variable
 typeid: to check type of a variable
 Pointers *
 References &
 
 declarations: header files get included into cpp files, like import in python
 definitions

 conditions

 String pointers: can be of 2 types: cstyle char* from cstring, use strcmp here
  or string from string library

Loops: for, while, do while

Pointers
Casting values

OOP - class
 
 */

#include <iostream>
#include <string>
#include "log.h"
#include <vector>
using namespace std;

#define DEF_LOG(x) cout << x << endl

bool sendAlertTemperatureThreshold(
    vector<float> temps, 
    float threshold, 
    unsigned int t,
    unsigned int window_length
    );

int multiply(int a, int b){
    return a * b;
}

void multiply_and_log(int a, int b){
    int res = multiply(a, b);
    cout << res << endl;
}

//using pointers
void increment_value(int* value){
    (*value)++; //notice the brackets for precedence
}
//using reference
void increment_value(int& value){
    value++; //no need to dereference as reference is passed
}

class Player{
public:
    int x, y; //by default, everything is private
    int speed;
};

void Move(Player& player, int xa, int ya){

}

int main(){
    // code to test sendAlertTemperatureThreshold 
    vector<float> temps = {1.0, 6.0, 6.0, 7.0, 9.0, 3.0, 2.0};
    bool val = sendAlertTemperatureThreshold(temps, 7.0, 3, 4);
    cout << "sendAlertTemperatureThreshold" << endl;
    if (val) 
        cout << "True" << endl;
    else
        cout << "False" << endl; 
    cout << "======================" << endl;
    val = sendAlertTemperatureThreshold(temps, 4.0, 2, 2);
    cout << "sendAlertTemperatureThreshold" << endl;
    if (val) 
        cout << "True" << endl;
    else
        cout << "False" << endl; 
    cout << "======================" << endl;
    return 0;















    int x = 6;
    bool comparisonResult = x == 5;
    if (comparisonResult)
        Log("Hello World!");
    // cstyle ptr, requires memory management
    const char* ptr = "heya";

    if (ptr)
        Log(ptr);
    if (ptr == "Hello")
        Log("Ptr is Hello");
    else
        Log("Ptr is Null");
    
    multiply_and_log(5, 6);
    // for loop
    int i=0; 
    bool condition = true;
    for (; condition; ){
        Log("Hello World!");
        i++;
        if (!(i < 3))
            condition = false;
    }

    // while
    int j = 0;
    while (j < 5){
        Log("it's been a while");
        j++;
    }

    // do while, will run atleast once no matter the condition
    do{
        Log("still ran");
    } while (j < 5);

    // control flow statements: continue, break(breaks the loop), return
    Log("================");

    for (int i = 0; i < 5; i++){
        if (i > 2)
            break;
        cout << i << endl;
    }
    Log("===============");
    Log("Pointers!!!!!!");
    Log("A pointer is an integer, that stores a memory address.");

    // type of pointer is the type of data stored at that pointer
    void* pointr = NULL;//nullptr; //NULL, not a valid memory address. Can't read from or write to it

    if (!pointr)
        Log("Null pointer!");

    int var = 9;
    void* void_ptr = &var; //still a valid memory address
    DEF_LOG(void_ptr);
    int* int_ptr = &var; //types matter for manipulation
    DEF_LOG(int_ptr);

    //dereferencing a pointer, changing the data stored at this memory address
    *int_ptr = 10; //notice the type is useful here
    DEF_LOG(var);

    //allocation of memory 
    char* buffer = new char[8]; //pointer to an 8 bytes of array, new kw means its 
    // dynamic allocation of memeory on the heap and returns a pointer to the beginning of the new memory block.
    // one should delete after use
    memset(buffer, 0, 8); //fills value, 0 is the value in 8 bytes of memory

    // double pointer: pointer to pointer
    char** double_ptr = &buffer;
    delete[] buffer; // delete the heap allocated memory after use

    //references: Pointer in disguise, can't be null pointer, can't change the reference
    int a = 5;
    int& ref_a = a; // its an alias to a
    DEF_LOG(typeid(ref_a).name());
    DEF_LOG(a);
    ref_a = 2; // directly modify the data stored at the memory address of variable
    DEF_LOG(a);
    //change value of a using a function and pointer
    increment_value(&a);
    DEF_LOG(a);
    increment_value(ref_a);//passing the alias
    DEF_LOG(a);
    increment_value(a);
    DEF_LOG(a);

    Player player;
    player.x = 8;
    DEF_LOG(player.x);
//    return 0; you can return any value
//    cin.get();
    
}
