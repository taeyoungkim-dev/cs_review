MEMORY_SIZE = 100
class My_que:
	def __init__(self,que_size):
		self.body = [None] * MEMORY_SIZE
		self.head = 0
		self.tail = 0
		self.max_size = que_size
	def push(self,num):
		if self.tail == MEMORY_SIZE :
			raise Exception("Queue reached end of memory")
		elif self.tail-self.head == que_size:
			raise Exception("Queue is full")
		else : 
			self.body[self.tail] = num
			self.tail += 1
	def pop(self):
		if self.head == self.tail :
			raise Exception("Queue is empty")
		else :
			self.head += 1
			return self.body[self.head - 1]
	def get_size(self):
		return self.tail - self.head
	def get_max_size(self):
		return self.max_size 
