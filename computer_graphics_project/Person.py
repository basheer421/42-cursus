from Circle import Circle
from Rect import Rect
import colors

class Person:
	def __init__(self, head_pos) -> None:
		self.head = Circle(head_pos[0], head_pos[1], 10, colors.SKIN, colors.SKIN)
		pos = (head_pos[0] - 10, head_pos[1] + 10)
		self.body = [
			Rect(pos[0] + 15, pos[1], 20, 30, 0, colors.BLACK, colors.BLACK),
			Rect(pos[0] - 15, pos[1], 20, 30, 0, colors.BLACK, colors.BLACK),
			Rect(pos[0], pos[1], 20, 30, 0, colors.BLACK, colors.CLOTHING)
		]
		self.legs = [
			Rect(pos[0] - 0 , pos[1] + 30, 10, 10, 0, colors.BLACK, colors.SHOE),
			Rect(pos[0] + 15, pos[1] + 30, 10, 10, 0, colors.BLACK, colors.SHOE)
		]
		self.hands = [
			Circle(pos[0] - 5, pos[1] + 15, 5, colors.BLACK, colors.SKIN),
			Circle(pos[0] + 20, pos[1] + 15, 5, colors.BLACK, colors.SKIN)
		]

		self.eyes = [
			Circle(head_pos[0] - 5, head_pos[1], 3, colors.BLACK, colors.BLACK),
			Circle(head_pos[0] + 5, head_pos[1], 3, colors.BLACK, colors.BLACK)
		]
		
		self.dx = .2
	
	def draw(self):
		self.head.draw()
		for body in self.body:
			body.draw()
		for leg in self.legs:
			leg.draw()
		for hand in self.hands:
			hand.draw()
		for eye in self.eyes:
			eye.draw()
	
	
	def translate(self, dx, dy):
		self.head.translate(dx, dy)
		for body in self.body:
			body.translate(dx, dy)
		for leg in self.legs:
			leg.translate(dx, dy)
		for hand in self.hands:
			hand.translate(dx, dy)
		for eye in self.eyes:
			eye.translate(dx, dy)
