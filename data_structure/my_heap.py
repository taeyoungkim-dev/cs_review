#Max heap : Parent Must be bigger than children
class My_heap:
	def __init__(self):
		self.body = []
		self.tail = 0
	def push(self,num):
		self.body.append(num)
		self._heapify_up(self.tail)
		self.tail += 1
	def pop(self):
		if self.tail == 0:
			raise Exception("Heap is empty")
		else :
			self.body[0] = self.body[self.tail-1]
			self.body.pop()
			self._heapify_down()
			if self.tail != 0:
				self.tail -= 1
	def _heapify_up(self,index):
		while True:
			if index==0 or self.body[(index-1)//2]>=self.body[index]:
				break
			else :
				self.body[(index-1)//2], self.body[index] = self.body[index], self.body[(index-1)//2]
				index = (index-1)//2
	def _heapify_down(self):
		index = 0
		while True:
			left_child_index = index*2+1
			right_child_index = left_child_index+1
			if right_child_index == tail:
				if self.body[left_child_index] > self.body[index]:
					self.body[left_child_index], self.body[index] = self.body[index], self.body[left_child_index]
					index = left_child_index
				else :
					break
			elif right_child_index > tail:
				break
			else :
				if self.body[left_child_index] > self.body[index]:
					if self.body[left_child_index] < self.body[right_child_index]:
						self.body[right_child_index], self.body[index] = self.body[index], self.body[right_child_index]
						index = right_child_index
					else:
						self.body[left_child_index], self.body[index] = self.body[index], self.body[left_child_index]
						index = left_child_index
				else :
					if self.body[right_child_index] > self.body[index]:			
						self.body[right_child_index], self.body[index] = self.body[index], self.body[right_child_index]
						index = right_child_index
					else :
						break
						
					 
				
			
				
				
		
