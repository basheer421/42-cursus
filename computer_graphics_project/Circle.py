from Shape import *
import math

class Circle(Shape):
	def __init__(self, x, y, radius,
								borderColor=(1.0, 1.0, 1.0),
								fillColor=(0, 0, 0)):

			super().__init__(x, y)
			self.radius = radius
			self.borderColor = borderColor
			self.fillColor = fillColor

	def draw(self):
			glPushMatrix()
			glTranslatef(self.x, self.y, 0)

			num_segments = 100
			angle_step = 2 * math.pi / num_segments

			# Draw filled circle
			glColor3f(*self.fillColor)
			glBegin(GL_TRIANGLE_FAN)
			glVertex2f(0, 0)  # Center of the circle
			for i in range(num_segments + 1):
					angle = i * angle_step
					x = self.radius * math.cos(angle)
					y = self.radius * math.sin(angle)
					glVertex2f(x, y)
			glEnd()

			# Draw circle border
			glColor3f(*self.borderColor)
			glBegin(GL_LINE_LOOP)
			for i in range(num_segments + 1):
					angle = i * angle_step
					x = self.radius * math.cos(angle)
					y = self.radius * math.sin(angle)
					glVertex2f(x, y)
			glEnd()

			glPopMatrix()

	def scale(self, factor):
			self.radius *= factor
			# super().scale(factor)
