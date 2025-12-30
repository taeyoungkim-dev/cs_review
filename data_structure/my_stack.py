class My_stack:
	def __init__(self,stack_size):
		self.top_index = -1
		self.body = []
		self.max_size = stack_size
	def push(self,num):
		if self.top_index < self.max_size - 1:
			self.body.append(num)
			self.top_index += 1
		else :
			print(f"You pushed {num} but stack is full")
	def pop(self):
		if self.top_index == -1:
			print("stack is empty")	
		else :
			return_num = self.body[self.top_index]
			self.body.pop()
			self.top_index -= 1
	def get_size(self):
		return self.top_index+1
	def get_max_size(self):
		return self.max_size
		
