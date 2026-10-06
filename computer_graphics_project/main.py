import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
from colors import *
from Rect import Rect
from Circle import Circle
from Triangle import Triangle
from Cloud import Cloud
from Tree import Tree
from Person import Person
from Drop import Drop
import random

pygame.init()
display = (SCREEN_WIDTH, SCREEN_HEIGHT)
pygame.display.set_mode(display, DOUBLEBUF | OPENGL)
pygame.display.set_caption("Computer graphics")

# Set up OpenGL orthographic projection for 2D rendering
glMatrixMode(GL_PROJECTION)
glLoadIdentity()
glOrtho(0, display[0], display[1], 0, -1, 1)
glMatrixMode(GL_MODELVIEW)

sky = Rect(0, 0, 800, 300, fillColor=BLUE, borderColor=BLUE)
grass = Rect(0, 300, 800, 300, fillColor=DGREEN, borderColor=DGREEN)
sun = Circle(70, 70, 40, fillColor=YELLOW, borderColor=YELLOW)

clouds = [
	Cloud(100, 150, 30),
	Cloud(300, 180, 30),
	Cloud(390, 120, 25),
	Cloud(500, 160, 30),
	Cloud(600, 155, 30)
]

rain = []
for cloud in clouds:
		for i in range(10):
				drop = Drop(cloud.x + random.randint(-20, 20), cloud.y + random.randint(-20, 20))
				rain.append(drop)

def animate_rain():
		for drop in rain:
				drop.move()
				if drop.y > SCREEN_HEIGHT:
						drop.reset(drop.x, random.randint(-20, -10))
				drop.draw()

tree = Tree(120, 400, 10, 50)
tree.rotate(15)
tree2 = Tree(300, 400, 10, 50)
taken_apple = Circle(0, 0, 3, fillColor=RED, borderColor=RED)

person = Person((250, 450))

water_lake = Circle(display[0], person.hands[0].y, 90, fillColor=BLUE, borderColor=BLUE)

scenes = [True, False, False]

clock = pygame.time.Clock()
target_fps = 60
ADDAPPLES = pygame.USEREVENT + 1
SCENE1END = pygame.USEREVENT + 2
SCENE2START = pygame.USEREVENT + 3
SCENE2END = pygame.USEREVENT + 4
SCENE3START = pygame.USEREVENT + 5
ADDAPPLES2 = pygame.USEREVENT + 6
SCENE3END = pygame.USEREVENT + 7

pygame.time.set_timer(ADDAPPLES, 15000, loops=1)
pygame.time.set_timer(SCENE1END, 20000, loops=1)
pygame.time.set_timer(SCENE2START, 22000, loops=1)
pygame.time.set_timer(SCENE2END, 34000, loops=1)
pygame.time.set_timer(SCENE3START, 36000, loops=1)
pygame.time.set_timer(ADDAPPLES2, 48000, loops=1)
pygame.time.set_timer(SCENE3END, 53000, loops=1)

while True:
	for event in pygame.event.get():
		if event.type == pygame.QUIT or \
				(event.type == pygame.KEYDOWN and event.key == pygame.K_ESCAPE):
			pygame.quit()
			quit()
		if (event.type == ADDAPPLES):
			tree.addApples()
		elif (event.type == SCENE1END):
			scenes[0] = False
		elif (event.type == SCENE2START):
			scenes[1] = True
		elif (event.type == SCENE2END):
			scenes[1] = False
		elif (event.type == SCENE3START):
			scenes[2] = True
		elif (event.type == ADDAPPLES2):
			tree2.addApples()
		elif (event.type == SCENE3END):
			scenes[2] = False
			pygame.quit()
			quit()

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	glLoadIdentity()
	time = pygame.time.get_ticks() // 1000

	
	if (scenes[0] == True):
		sky.draw()
		grass.draw()
		sun.draw()
		water_lake.draw()
		if (time > 5):
			tree.draw()

		for cloud in clouds:
			cloud.animate()
			cloud.draw()
		
		animate_rain()

		if (time > 5) and (time < 19):
			tree.animate()

	elif (scenes[1] == True):
		sky.draw()
		grass.draw()
		sun.draw()
		person.draw()
		water_lake.draw()
		tree.draw()
		person.draw()
		for cloud in clouds:
			cloud.animate()
			cloud.draw()
		if (time < 28):
			person.translate(-person.dx, 0)
		elif (time < 32):
			person.translate(person.dx, 0)
			taken_apple.x = person.hands[0].x
			taken_apple.y = person.hands[0].y
			taken_apple.draw()

	elif (scenes[2] == True):
		sky.draw()
		grass.draw()
		sun.draw()
		person.draw()
		water_lake.draw()
		tree.draw()
		person.draw()
		for cloud in clouds:
			cloud.animate()
			cloud.draw()
		animate_rain()
		if (time > 45):
			if (time < 53):
				tree2.animate()
			tree2.draw()

	pygame.display.flip()
	clock.tick(target_fps)
