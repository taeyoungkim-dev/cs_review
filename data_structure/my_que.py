class My_que:
	def __init__(self,que_size):
		self.body = []
		self.size = 0
		self.max_size = que_size
	def push(self,num):
		if self.size == que_size:
			print("Queue is full")
		else : 
			self.body.append(num)
			self.size += 1
	def pop(self):
		if self.size == 0:
			print("Queue is empty")
		else :
			self.size -= 1
			return_value = self.body.pop(0)
			return return_value
	def get_size(self):
		return self.size
	def get_max_size(self):
		return self.max_size 
