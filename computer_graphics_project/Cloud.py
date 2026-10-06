from Circle import Circle

class Cloud:
  def __init__(self, x, y, radius):
    self.x = x
    self.y = y
    self.radius = radius
    self.borderColor = (255, 255, 255)
    self.fillColor = (255, 255, 255)
    self.circles = [
      Circle(x, y, radius, self.borderColor, self.fillColor),
      Circle(x + 20, y, radius, self.borderColor, self.fillColor),
      Circle(x + 30, y - 20, radius, self.borderColor, self.fillColor),
      Circle(x + 40, y, radius, self.borderColor, self.fillColor),
      Circle(x + 60, y, radius, self.borderColor, self.fillColor)
    ]
    self.dx = .2

  def draw(self):
    for circle in self.circles:
      circle.draw()  

  def translate(self, dx, dy):
    for circle in self.circles:
      circle.translate(dx, dy)
  
  def scale(self, factor):
    for circle in self.circles:
      circle.scale(factor)
  
  def animate(self):
    if (self.circles[0].x + self.radius) >= 800 or (self.circles[4].x - self.radius) <= 0:
      self.dx *= -1
    self.translate(self.dx, 0)
