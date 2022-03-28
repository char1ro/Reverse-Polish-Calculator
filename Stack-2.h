//
// Created by charl on 11/5/2021.
//
#include <cstdint>
#include <vector>
#include <iostream>
#include <cstring>

#ifndef PROJECT_2_STACK_H
#define PROJECT_2_STACK_H
template<typename T>
class Stack {
    // initialize internal queue
    std::vector<T> stack;

public:
    // Constructor
    Stack()=default;

    void setCapacity(int capacity){
        stack.resize(capacity);
    }
    void Push(T data) {
        stack.push_back(data);
    }
    T *Pop() {
        // Check the queue length
        if (stack.empty())
            return nullptr;
        stack.pop_back();
    }
    T Size() {
        //return size of queue
        return stack.size();
    }
    T Top() {
        //return top element
        return stack.back();
    }

    void printStack() {
        //print queue
        for (uint64_t i = 0; i < stack.size(); i++) {
            std::cout << stack.at(i) << std::endl;
        }
    }
    //evaluation
    double Evaluate(){
        double operand1,operand2; //initialize operands as double
        std::string operation = stack.back(); //set the last string segment to operation
        stack.pop_back(); //delete it from stack
        if(stack.back()=="*" || stack.back()=="+" || stack.back()=="/" || stack.back()=="-"){ //check if it is an operation instead
            std::cout<<"2nd operand"<<std::endl; //test
            operand2=Evaluate(); //recursive call to put the operator into operation
        }
        else{
            operand2 = std::stod(stack.back()); //turn string segment from stack into double operand
            stack.pop_back(); //delete from stack
        }
        if(stack.back()=="*" || stack.back()=="+" || stack.back()=="/" || stack.back()=="-"){ //check if it is an operation instead
            std::cout<<"1st operand"<<std::endl; //test
            operand1 = Evaluate(); //recursive call to put the operator into operation
        }
        else {
            operand1 = std::stod(stack.back()); //turn string segment from stack into double operand
            stack.pop_back(); //delete from stack
        }
        if (operation == "*"){ //multiply operands if the operation is *
            std::cout<<"multiply"<<std::endl; //test
            std::cout<<operand2<<"*"<<operand1<<std::endl;
            return operand1 * operand2;
        }
        else if(operation == "+"){ //add operands if the operation is +
            std::cout<<"add"<<std::endl; //test
            std::cout<<operand1<<"+"<<operand2<<std::endl;
            return operand1 + operand2;
        }
        else if(operation == "/"){ //divide operands if the operation is /
            std::cout<<"divide"<<std::endl; //test
            std::cout<<operand1<<"/"<<operand2<<std::endl;
            return operand1 / operand2;
        }
        else if(operation == "-"){ //subtract operands if the operation is -
            std::cout<<"subtract"<<std::endl; //test
            std::cout<<operand1<<"-"<<operand2<<std::endl;
            return operand1 - operand2;
        }
    }
    //destructor
    ~Stack() = default;
};
#endif //PROJECT_2_STACK_H
