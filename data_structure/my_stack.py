class My_stack:
	def __init__(self,stack_size):
		self.tail = 0
		self.body = [None] * stack_size
		self.max_size = stack_size
	def push(self,num):
		if self.tail < self.max_size:
			self.body[tail] = num
			self.tail += 1
		else :
			raise Exception("Stack is full")
	def pop(self):
		if self.tail == 0:
			raise Exception("Stack is empty")
		else :
			self.tail -= 1
	def get_size(self):
		return self.tail
	def get_max_size(self):
		return self.max_size
		
