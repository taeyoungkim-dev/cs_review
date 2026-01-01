# head : pop할 칸의 index
# tail : push 할 칸의 index
# 모든 칸에 요소를 넣는다면 head == tail 일 때 full과 empty 모두 될 수 있다.
# 따라서 한칸의 저장공간을 포기하고 head == tail : empty, head-1 == tail : full 로
# 만든다.  
class Circular_que:
	def __init__(self,que_size):
		self.max_size = que_size
		self.body = [None] * que_size
		self.head = 0
		self.tail = 0
	def push(self,num):
		if self.head == self._check_head_tail(self.tail+1):
			raise Exception("Queue is full")
		else :
			self.body[self.tail] = num
			self.tail = self._check_head_tail(self.tail+1)
	def pop(self):
		if self.head == self.tail :
			raise Exception("Cir_que is empty")
		else :
			return_v = self.body[self.head]
			self.head = self._check_head_tail(self.head+1)
			return return_v
	def get_size(self):
		return (self.tail - self.head + self.max_size)%self.max_size
	def get_max_size(self):
		return self.max_size
	def _check_head_tail(self,head_or_tail):
		if head_or_tail == self.max_size :
			head_or_tail = 0
		elif head_or_tail == -1 :
			head_or_tail = self.max_size - 1
		return head_or_tail			
