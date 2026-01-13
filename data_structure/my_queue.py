#TODO
class My_queue:
    def __init__(self,queue_size=100):
        self.__memory_size = 100
        self.__body = [0]*__memory_size
        self.__max_size = queue_size
        self.__head = 0
        self.__tail = 0
    def push(self,num:int)->None:
        if self.__tail == self.__memory_size:
            raise IndexError("Queue is out of valid memory")
        elif self.__tail - self.__head == self.max_size:
            raise IndexError("Queue is full")
        else :
            self.__body[self.__tail] = num
            self.__tail += 1
    def pop(self)->int:
        if self.__head == self.__tail:
            raise IndexError("Queue is emtpy")
        else :
            self.__head += 1
            return self.__body[self.__head-1]
    def get_size(self)->int:
        return self.__tail-self.__head
    def get_max_size(self)->int:
        return self.__max_size


my_que = My_queue(30)
print(f("my_que_size = {my_que.get_size()}")
print(f("my_que_max_size = {my_que.get_max_size()}")
for i in range(31):
    try:
        my_que.push(i)
    except IndexError as e:
        print(e)
for _ in range(31):
    try:
        my_que.pop():
    except IndexError as e:
        print(e)

