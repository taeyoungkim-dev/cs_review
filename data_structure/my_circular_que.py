class Circular_que:
	def __init__(self,que_size):
		self.max_size = que_size
		self.body = [None] * que_size
		self.head = 0
		self.tail = 1
	def push(self,num):
		if head == tail:
			print("Cir_que is full")
		else :
			self.body[_check_head_tail(self.tail-1)] = num
			self.tail = _check_head_tail(self.tail+1)]
	def pop(self):
		if self.head == _check_head_tail(self.tail-1) :
			print("Cir_que is empty")
		else :
			return_v = self.body[self.head]
			self.head = _check_head_tail(self.head-1)
			return return_v
	def get_size(self):
		return 
	def _check_head_tail(self,head_or_tail):
		if head_or_tail == self.max_size :
			head_or_tail = 0
		elif head_or_tail == -1 :
			head_or_tail == self.max_size - 1
		return head_or_tail			
