import pygame
from pygame.locals import *
from OpenGL.GL import *
from OpenGL.GLU import *

import random
import sys

# Initialize Pygame
pygame.init()

# Set up display
screen = pygame.display.set_mode((800, 600))
pygame.display.set_caption("Sky, Clouds, and Grass")


# Colors
BLUE = (135, 206, 235)  # Light Blue for the sky
DGREEN = (34, 139, 34)    # Dark Green for the grass
BLACK = (0, 0, 0)      # Black
WHITE = (255, 255, 255)  # White for clouds
YELLOW = (255, 255, 0)  # Yellow for clouds
GREEN = (0, 128, 0)   # Green for leaves
RED = (255, 0, 0)    #Red


# Main loop
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

    # Fill top half with blue for the sky
    screen.fill(BLUE, (0, 0, 800, 300))
     # Fill bottom half with green for the grass
    screen.fill(DGREEN, (0, 300, 800, 300))

    # Draw yellow sun in the sky
    pygame.draw.circle(screen, YELLOW, (70, 70), 40)

    # Draw white cloud shapes in the sky
    for _ in range(1):
        pygame.draw.circle(screen, WHITE, (100, 150), 30)
        pygame.draw.circle(screen, WHITE, (120, 150), 30)
        pygame.draw.circle(screen, WHITE, (130, 130), 30)
        pygame.draw.circle(screen, WHITE, (140, 150), 30)
        pygame.draw.circle(screen, WHITE, (160, 150), 30)


    pygame.draw.circle(screen, WHITE, (300, 150), 30)
    pygame.draw.circle(screen, WHITE, (320, 150), 30)
    pygame.draw.circle(screen, WHITE, (330, 130), 30)
    pygame.draw.circle(screen, WHITE, (340, 150), 30)
    pygame.draw.circle(screen, WHITE, (360, 150), 30)

    pygame.draw.circle(screen, WHITE, (390, 150), 25)
    pygame.draw.circle(screen, WHITE, (420, 150), 30)
    pygame.draw.circle(screen, WHITE, (430, 130), 30)
    pygame.draw.circle(screen, WHITE, (440, 150), 30)
    pygame.draw.circle(screen, WHITE, (460, 150), 20)

    pygame.draw.circle(screen, WHITE, (590, 150), 20)
    pygame.draw.circle(screen, WHITE, (520, 150), 30)
    pygame.draw.circle(screen, WHITE, (530, 130), 30)
    pygame.draw.circle(screen, WHITE, (540, 150), 30)
    pygame.draw.circle(screen, WHITE, (570, 150), 20)

   
    pygame.draw.circle(screen, WHITE, (560, 150), 30)
    pygame.draw.circle(screen, WHITE, (570, 150), 30)
    pygame.draw.circle(screen, WHITE, (580, 130), 30)
    pygame.draw.circle(screen, WHITE, (590, 150), 30)
    pygame.draw.circle(screen, WHITE, (600, 150), 30)

    #  # Draw the tree trunk
    pygame.draw.rect(screen, (139, 69, 19), (130, 425, 40, 100))


    # # Draw the tree top (leaves) closer to the trunk
    pygame.draw.circle(screen, GREEN, (150, 425), 50)
    pygame.draw.circle(screen, GREEN, (100, 425), 50)
    pygame.draw.circle(screen, GREEN, (200, 425), 50)
    pygame.draw.circle(screen, GREEN, (150, 375), 50)
    pygame.draw.circle(screen, GREEN, (125, 400), 50)
    pygame.draw.circle(screen, GREEN, (175, 400), 50)

            # Draw the palm tree trunk
    pygame.draw.rect(screen, (139, 69, 19), (190, 200, 20, 100))

        # Draw the lower triangle
    pygame.draw.polygon(screen, GREEN, [(200, 180), (160, 260), (240, 260)])

        # Draw the upper triangle
    pygame.draw.polygon(screen, GREEN, [(200, 180), (175, 220), (225, 220)])

     # Draw the second (right) palm tree trunk
    pygame.draw.rect(screen, (139, 69, 19), (590, 200, 20, 100))

        # Draw the lower triangle
    pygame.draw.polygon(screen, GREEN, [(600, 180), (560, 260), (640, 260)])

        # Draw the upper triangle
    pygame.draw.polygon(screen, GREEN, [(600, 180), (575, 220), (625, 220)])

        # Draw the house with the latest modifications
    pygame.draw.rect(screen, (245, 245, 245), (300, 200, 200, 150))  # Off-white lower level
    pygame.draw.polygon(screen, (139, 69, 19), [(280, 200), (400, 100), (520, 200)])  # Bigger brown roof

    # Add two blue windows divided into four smaller squares
    window_color = (135, 206, 250)  # Light blue color for windows
    pygame.draw.rect(screen, window_color, (330, 230, 30, 30))
    pygame.draw.rect(screen, window_color, (450, 230, 30, 30))

    # Adjusted smaller brown door with a yellow handle
    pygame.draw.rect(screen, (139, 69, 19), (390, 310, 20, 40))  # Smaller brown door
    pygame.draw.circle(screen, (255, 255, 0), (400, 340), 2)  # Yellow door handle reduce them with the same ratio

    #apples
    pygame.draw.circle(screen, RED, (155, 425), 5)  # Main apple circle
    pygame.draw.circle(screen, RED, (121, 420), 5)  # Main apple circle
    pygame.draw.circle(screen, RED, (190, 405), 5)  # Main apple circle
    pygame.draw.circle(screen, RED, (150, 375), 5)  # Main apple circle
    pygame.draw.circle(screen, RED, (125, 400), 5)  # Main apple circle
    pygame.draw.circle(screen, RED, (125, 400), 5)  # Main apple circle


    # Define colors
    skin_color = (255, 218, 185)
    clothing_color = (0, 128, 0)
    shoe_color = (128, 0, 0)
    hat_color = (0, 0, 255)


    pygame.draw.circle(screen, skin_color, (320, 450), 20)  # Head
    pygame.draw.rect(screen, BLACK, (295, 470, 50, 50))  # Body


    pygame.draw.rect(screen, hat_color, (285, 470, 25, 50))  # Left arm
    pygame.draw.rect(screen, hat_color, (330, 470, 25, 50))  # Right arm

    pygame.draw.rect(screen, BLACK, (295, 520, 20, 30))  # Left leg
    pygame.draw.rect(screen, BLACK, (315, 520, 20, 15))  # between
    pygame.draw.rect(screen, BLACK, (325, 520, 20, 30))  # Right leg

    pygame.draw.rect(screen, WHITE, (298, 550, 15, 15))  # Left shoe
    pygame.draw.rect(screen, WHITE, (328, 550, 15, 15))  # Right shoe
    pygame.draw.circle(screen, (0, 0, 0), (305, 450), 5)  # Left eye
    pygame.draw.circle(screen, (0, 0, 0), (320, 450), 5)  # Right eye


    # Draw the hat
    pygame.draw.rect(screen, hat_color, (300, 420, 40, 20))  # Hat base
    pygame.draw.rect(screen, hat_color, (288, 433, 14, 7))  # Hat base # Hat line

    # Draw the hands holding a watering can
    pygame.draw.circle(screen, skin_color, (295, 499), 10)  # Left hand
    pygame.draw.circle(screen, skin_color, (345, 499), 10)  # Right hand

    #draw a water tank
    pygame.draw.rect(screen, WHITE, (600, 470, 150, 70))  # water tank
    pygame.draw.rect(screen, YELLOW, (270, 499, 330, 10))  # water pipe

    # Update the display

    pygame.display.update()