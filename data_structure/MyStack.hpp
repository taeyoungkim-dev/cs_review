#pragma once
#include <stdexcept>
class MyStack{
    private:
        int *body = nullptr;
        int tail = 0;
        int max_size;
    public:
        MyStack(int stack_size){
            max_size = stack_size;
            this->body = new int[stack_size]; 
        }
        ~MyStack(){
            delete[] body;
        }
        void push(int num){
            if(max_size==tail){
               throw  std::out_of_range("Error: Accessing wrong index");
            }
            body[tail] = num;
            ++tail;
        }
        int pop(){
           if(tail==0){
                throw std::out_of_range("Error: Accessing wrong index");
           }
           --tail;
           return body[tail];
        }
        int size(){
            return tail;
        }
        int get_max_size(){
            return this->max_size;
        }
};