import pygame
import random

pygame.init()

SQUARE_SIZE = 20
BACKGROUND_COLOR = (0, 0, 0)
WALL_COLOR = (255, 255, 255)
NUM_ROW = 5
NUM_COLUMN = 5

SCREEN = pygame.display.set_mode((SQUARE_SIZE * NUM_ROW, SQUARE_SIZE * NUM_COLUMN))
CLOCK = pygame.time.Clock()

GRAPH = [
    # left, top, right, bottom
]

def evalute_border():
    value = random.randint(0, 3)
    return value if value == 0 else 1


def generate_graph():
    result = NUM_COLUMN * NUM_ROW
    count = 0
    visited = []
    frontier = [
        {"start": (0,0), "end": (0,1), "value": 0},
        {"start": (0,0), "end": (1,0), "value": 0}
    ]

    while len(frontier) != 0:
        node = frontier.pop(0)
        visited.append(node)

        chields = [
            {"start": node["end"], "end": (node["end"][0] + 1, node["end"][1]), "value": evalute_border()},
            {"start": node["end"], "end": (node["end"][0] - 1, node["end"][1]), "value": evalute_border()},
            {"start": node["end"], "end": (node["end"][0], node["end"][1] + 1), "value": evalute_border()},
            {"start": node["end"], "end": (node["end"][0], node["end"][1] - 1), "value": evalute_border()},
        ]

        for chield in chields:
            if chield["end"][0] < 0 or chield["end"][0] >= NUM_COLUMN or \
               chield["end"][1] < 0 or chield["end"][1] >= NUM_ROW:
                continue

            if len([el for el in visited if chield["start"] == el["start"] and chield["end"] == chield["end"]]) == 0 and \
               len([el for el in frontier if chield["start"] == el["start"] and chield["end"] == chield["end"]]) == 0:
                frontier.append(chield)
                
    return visited

def draw_sqaure(x, y, color):
    # x, y, w, h
    pygame.draw.rect(
        SCREEN, color, (SQUARE_SIZE * x, SQUARE_SIZE * y, SQUARE_SIZE, SQUARE_SIZE)
    )

def draw_border(start, end):
    pygame.draw.line(
        SCREEN, WALL_COLOR, 
        (SQUARE_SIZE * start[0], SQUARE_SIZE * start[1]), 
        (SQUARE_SIZE * end[0], SQUARE_SIZE * end[1])
    )

GRAPH = generate_graph()
print(GRAPH)
running = True

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    SCREEN.fill(BACKGROUND_COLOR)

    for el in GRAPH:
        if el["start"][0] > el["end"][0]:
            draw_border(el["start"], (el["end"][0] + 1, el["end"][1] + 1))
            
        if el["start"][0] < el["end"][0]:
            draw_border((el["start"][0] + 1, el["start"][1] + 1), el["end"])

        if el["start"][1] > el["end"][1]:
            draw_border(el["start"], (el["end"][0] + 1, el["end"][1] + 1))

        if el["start"][1] < el["end"][1]:
            draw_border((el["start"][0] + 1, el["start"][1] +1), el["end"])

    pygame.display.flip()
    CLOCK.tick(60)

pygame.quit()
