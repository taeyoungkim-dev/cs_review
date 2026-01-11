#include <iostream>
#include <stdexcept>

class MyCircularQueue{
	private:
		int *body = nullptr;
		int head = 0;
		int tail = 0;
		int max_size;
		int _correction(int index){
			if(index==max_size) return 0;
			if (index==-1) return max_size-1;
			return index;	
}
	public: 
		MyCircularQueue(int queue_size){
			body = new int[queue_size+1];
			max_size = queue_size;
		}
		~MyCircularQueue(){
			delete[] body;
}
		void push(int num){
			if(_correction(head-1)==tail)
				throw std::out_of_range("Queue is full");
			body[tail] = num;
			tail = _correction(tail+1); 
}
		int pop(){
			if(head==tail)
				throw std::out_of_range("Queue is empty");
			int temp = body[head];
			head = _correction(head+1);
			return temp;
}
		int get_size(){return (tail-head+max_size)%max_size;}
		int get_max_size(){return max_size;} 
};
