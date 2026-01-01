from my_circular_que import *
class My_priority_que:
	def __init__(self,high_que_size, mid_que_size=high_que_size, low_que_size = high_que_size):
		self.max_size = high_que_size + mid_que_size + low_que_size
		self.high_que = My_circular_que(high_que_size)
		self.mid_que = My_circular_que(mid_que_size)
		self.low_que = My_circular_que(low_que_size) 
				 
