from Rect import Rect
from colors import *
import random
import math

class Drop:
	def __init__(self, x, y):
		self.x = x
		self.y = y
		self.size = random.randint(1, 3)
		self.speed = random.uniform(1, 3)
		self.horizontal_speed = random.uniform(-1, 1)

		self.drop = Rect(x, y, 1, 10 * self.size, fillColor=BLUE, borderColor=BLUE)

	def draw(self):
		self.drop.draw()

	def move(self):
		
		self.x += self.horizontal_speed
		self.y += self.speed
		self.drop.translate(self.horizontal_speed, self.speed)

		# If the drop goes below the screen, reset its position above the screen
		if self.y > SCREEN_HEIGHT:
			self.reset(random.randint(0, SCREEN_WIDTH), random.randint(-20, -10))

	def reset(self, x, y):
		self.x = x
		self.y = y
		self.drop.x = x
		self.drop.y = y
