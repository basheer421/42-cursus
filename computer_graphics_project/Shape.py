import math
from OpenGL.GL import *
from OpenGL.GLU import *

class Shape:
    def __init__(self, x, y, angle = 0):
        self.x = x
        self.y = y
        self.angle = angle

    def translate(self, deltaX, deltaY):
        self.x += deltaX
        self.y += deltaY

    def scale(self, factor):
        self.x *= factor
        self.y *= factor
    
    # Rotate counter clockwise in degrees
    def rotate(self, angle):
        self.angle += angle
        self.angle %= 360

    def __str__(self):
        return (
          f"{__class__.__name__}: {self.x, self.y}, angle: {self.angle}"
        )

    def draw(self):
        ...
