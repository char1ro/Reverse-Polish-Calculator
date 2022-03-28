#include <iostream>
#include "Stack.h"

std::string InfixToRPN(){

}

int main(int argument, char *argumentElement[])
{
    Stack<std::string> s;
    for(int i=0; i<argument; i++){
        s.Push(argumentElement[i]);
    }

    InfixToRPN();

    std::cout<< s.Evaluate();
    return 0;
}
