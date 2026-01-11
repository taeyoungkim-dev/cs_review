#include <iostream>
#include <stdexcept>

class MyQueue{
	private:
		int *body = NULL;
		int head = 0;
		int tail = 0;
		int max_size;
	public:
		MyQueue(int que_size){
			this->max_size = que_size;
			body = new int[que_size];
		}
		~MyQueue(){
			delete[] body;
		}
		void push(int num){
			if(tail==max_size){
				throw std::out_of_range("Accessing wrong index");
			}
			body[tail++] = num;	
		}
		int pop(){
			if(head==tail){
				throw std::out_of_range("Queue is empty");
				
			}
			++head;
			return body[head-1];
		}
		int get_size(){
			return tail-head;
		}
		int get_max_size(){
			return max_size;
		}
};
