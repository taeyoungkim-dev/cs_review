#Max heap : Parent Must be bigger than children
class My_heap:
	def __init__(self):
		self.body = []
		self.tail = 0
	def push(self,num):
		self.body.append(num)
		self._heapify_up(tail)
		self.tail += 1
	def pop(self):
		if self.tail = 0:
			raise Exception("Heap is empty")
		else :
			self.body[0] = self.body[self.tail-1]
			self.body.pop()
			self._heapify_down()
			self.tail -= 1
	def _heapify_up(self,index):
		while True:
			if index==0 or self.body[index/2-1]>=self.body[index]:
				break
			else :
				self.body[index/2-1], self.body[index] = self.body[index], self.body[index/2-1]
				
				
		
