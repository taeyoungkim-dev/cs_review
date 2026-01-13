class My_stack:
    def __init__(self,stack_size=100):
        self.__body = [0]*100 
        self.__tail = 0
        self.__max_size = stack_size
    def push(self,num:int)->None:
        if self.__tail==self.__max_size:
            raise IndexError("Stack is full")
        else :
            self.__body[self.__tail] = num
            self.__tail += 1
    def pop(self)->int:
        if self.__tail==0:
            raise IndexError("Stack is empty")
        else :
            self.__tail -= 1
            return self.__body[self.__tail]
    def get_size(self)->int:
        return self.__tail
    def get_max_size(self)->int:
        return self.__max_size


#Validation
my_stack = My_stack(30)
print(f"stack_size : {my_stack.get_size()}")
print(f"stack_max_size : {my_stack.get_max_size()}")
for i in range(31):
    try:
        my_stack.push(i)
    except IndexError as e:
        print(e)
for _ in range(31):
    try:
        my_stack.pop()
    except IndexError as e:
        print(e)
