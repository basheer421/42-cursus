from Shape import *

class Triangle(Shape):
  def __init__(self, p1, p2, p3,
                angle=0,
                borderColor=(1.0, 1.0, 1.0),
                fillColor=(0, 0, 0)):

    super().__init__(p1[0], p1[1])
    self.p1 = p1
    self.p2 = p2
    self.p3 = p3
    self.borderColor = borderColor
    self.fillColor = fillColor
    self.updateVertices()
    self.rotate(angle)

  def draw(self):
    glPushMatrix()

    glTranslatef(self.center[0], self.center[1], 0)
    glRotatef(self.angle, 0, 0, 1)
    glTranslatef(-self.center[0], -self.center[1], 0)

    glColor3f(*self.fillColor)
    glBegin(GL_TRIANGLES)
    for x, y in self.vertices:
      glVertex2f(x, y)
    glEnd()

    glColor3f(*self.borderColor)
    glBegin(GL_LINES)
    for i in range(3):
      glVertex2f(*self.vertices[i])
      glVertex2f(*self.vertices[(i + 1) % 3])
    glEnd()

    glPopMatrix()

  def scale(self, factor):
    self.p1 = ((self.p1[0] - self.center[0]) * factor + self.center[0],
      (self.p1[1] - self.center[1]) * factor + self.center[1])
    self.p2 = ((self.p2[0] - self.center[0]) * factor + self.center[0],
      (self.p2[1] - self.center[1]) * factor + self.center[1])
    self.p3 = ((self.p3[0] - self.center[0]) * factor + self.center[0],
      (self.p3[1] - self.center[1]) * factor + self.center[1])

    self.updateVertices()
  
  def rotate(self, angle):
    self.angle += angle
    self.updateVertices()

  def translate(self, dx, dy):
    self.p1 = (self.p1[0] + dx, self.p1[1] + dy)
    self.p2 = (self.p2[0] + dx, self.p2[1] + dy)
    self.p3 = (self.p3[0] + dx, self.p3[1] + dy)
    self.updateVertices()

  def updateVertices(self):
    self.center = ((self.p1[0] + self.p2[0] + self.p3[0]) / 3,
      (self.p1[1] + self.p2[1] + self.p3[1]) / 3)
    self.vertices = [
      self.p1,
      self.p2,
      self.p3
    ]
