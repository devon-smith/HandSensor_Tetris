#include "shapes.h"
#include "mymodule.h"
#include "uart.h"
#include "timer.h"
#include "gl.h"
#include "printf.h"
#include "armtimer.h"

/* Color reference:
#define GL_BLACK    0xFF000000
#define GL_WHITE    0xFFFFFFFF
#define GL_RED      0xFFFF0000 (1)
#define GL_GREEN    0xFF00FF00 (2)
#define GL_BLUE     0xFF0000FF (3)
#define GL_CYAN     0xFF00FFFF (4)
#define GL_MAGENTA  0xFFFF00FF (5)
#define GL_YELLOW   0xFFFFFF00 (6)
#define GL_AMBER    0xFFFFBF00
#define GL_ORANGE   0xFFFF3F00
#define GL_PURPLE   0xFF7F00FF
#define GL_INDIGO   0xFF000040
#define GL_CAYENNE  0xFF400000 (7)
#define GL_MOSS     0xFF004000
#define GL_SILVER   0xFFBBBBBB
*/


const char SHAPE[7][4][4][4] = // 7 shapes, 4 orientations each, 4 y cordinates, 4 x cordinates 
{
    { // I-shape
        {
            {0, 0, 0, 0}, 
            {1, 1, 1, 1}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0}, 
            {0, 0, 1, 0}, 
            {0, 0, 1, 0}, 
            {0, 0, 1, 0}
        },
        {
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}, 
            {1, 1, 1, 1}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 1, 0, 0}
        }
    },
    { // J-shape
        {
            {1, 0, 0, 0}, 
            {1, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 0}, 
            {0, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0}, 
            {1, 1, 1, 0}, 
            {0, 0, 1, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {1, 1, 0, 0}, 
            {0, 0, 0, 0}
        }
    },
    { // L-shape
        {
            {0, 0, 1, 0}, 
            {1, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0}, 
            {1, 1, 1, 0}, 
            {1, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {1, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 0, 0, 0}
        }
    },
    { // O-shape
        {
            {0, 1, 1, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 1, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        }
    },
    { // S-shape
        {
            {0, 1, 1, 0}, 
            {1, 1, 0, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 1, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0}, 
            {0, 1, 1, 0}, 
            {1, 1, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {1, 0, 0, 0}, 
            {1, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 0, 0, 0}
        }
    },
    { // T-shape
        {
            {0, 1, 0, 0}, 
            {1, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0}, 
            {0, 1, 1, 0}, 
            {0, 1, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0}, 
            {1, 1, 1, 0}, 
            {0, 1, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0}, 
            {1, 1, 0, 0}, 
            {0, 1, 0, 0}, 
            {0, 0, 0, 0}
        }
    },
    { // Z-shape
        {
            {1, 1, 0, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 0, 1, 0}, 
            {0, 1, 1, 0}, 
            {0, 1, 0, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 0, 0, 0}, 
            {1, 1, 0, 0}, 
            {0, 1, 1, 0}, 
            {0, 0, 0, 0}
        },
        {
            {0, 1, 0, 0}, 
            {1, 1, 0, 0}, 
            {1, 0, 0, 0}, 
            {0, 0, 0, 0}
        }
    }
};

color_t COLOR[7] = {GL_CYAN, GL_MAGENTA, GL_ORANGE, GL_YELLOW, GL_RED, GL_PURPLE, GL_GREEN};

// Private helper function to generate random number
static unsigned int rand(unsigned int seed) {
    unsigned int z1 = seed;
    unsigned int z2 = seed;
    unsigned int z3 = seed;
    unsigned int z4 = seed;
    unsigned int b;

    b  = ((z1 << 6) ^ z1) >> 13;
    z1 = ((z1 & 4294967294U) << 18) ^ b;
    b  = ((z2 << 2) ^ z2) >> 27;
    z2 = ((z2 & 4294967288U) << 2) ^ b;
    b  = ((z3 << 13) ^ z3) >> 21;
    z3 = ((z3 & 4294967280U) << 7) ^ b;
    b  = ((z4 << 3) ^ z4) >> 12;
    z4 = ((z4 & 4294967168U) << 13) ^ b;
    return (z1 ^ z2 ^ z3 ^ z4);
}

/* This private helper function produces a random number 
   between one and six, for use in getting color
   and shape shape. */
static unsigned int randomizer(void) {
    unsigned int randomnum = timer_get_ticks();
    randomnum = rand(randomnum); 
    return (randomnum % 7);
}

/* This function produces a random shape in the starting orientation
   using the randomizer and the get_shape function. */
shape_t random_start_shape(void) {

    int shapeNum = randomizer();

    return get_shape(shapeNum, 0);
}


/* This function takes a int "shape",
   which indicates which type of shape it is. The 
   "shape" value is determined by a randomizer, to 
   be written later. */
shape_t get_shape(int requestedshape, int requestedorientation) {
    shape_t shape;

    shape.type = requestedshape;
    shape.color = COLOR[requestedshape];
    shape.orientation = 0;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            shape.map[y][x] = SHAPE[requestedshape][requestedorientation][y][x];
        }
    }

    return shape;
}

void draw_shape_raw(int x, int y, shape_t shape, unsigned int blocksize) {
    for (int mapY = 0; mapY < 4; mapY++) {
        for (int mapX = 0; mapX < 4; mapX++) {
            if (shape.map[mapY][mapX] == 1) 
                draw_square_with_bound(x + mapX*blocksize, y + mapY*blocksize, blocksize, shape.color);
        }
    }
}

void draw_shape(int x, int y, shape_t shape) {
    armtimer_disable();
    for (int mapY = 0; mapY < 4; mapY++) {
        for (int mapX = 0; mapX < 4; mapX++) {
            if (shape.map[mapY][mapX] == 1) draw_block(x + mapX, y + mapY, shape.color);
        }
    }
    armtimer_enable();
}

void draw_shadow(int x, shape_t shape, color_t BACKGROUND_COLOR) {
    armtimer_disable();

    int y = lowest_spot();

    for (int mapY = 0; mapY < 4; mapY++) {
        for (int mapX = 0; mapX < 4; mapX++) {
            if (shape.map[mapY][mapX] == 1) draw_block(x + mapX, y + mapY, BACKGROUND_COLOR);
        }
    }
    armtimer_enable();
}

void clear_shadow(int x, shape_t shape) {
    armtimer_disable();

    int y = lowest_spot();

    for (int mapY = 0; mapY < 4; mapY++) {
        for (int mapX = 0; mapX < 4; mapX++) {
            if (shape.map[mapY][mapX] == 1) clear_block(x + mapX, y + mapY);
        }
    }
    armtimer_enable();
}



void clear_shape(int x, int y, shape_t shape) {
    armtimer_disable();
    for (int mapY = 0; mapY < 4; mapY++) {
        for (int mapX = 0; mapX < 4; mapX++) {
            if (shape.map[mapY][mapX] == 1) clear_block(x + mapX, y + mapY);
        }
    }
    armtimer_enable();
}

void place_shape(int x, int y, shape_t shape, char** placedblocks, unsigned int NUM_ROWS, unsigned int NUM_COLS) {
    for (int mapY = 0; mapY < 4; mapY++) {
        for (int mapX = 0; mapX < 4; mapX++) {
            if ((x + mapX) < NUM_COLS && (y + mapY) < NUM_ROWS) {
                if (shape.map[mapY][mapX] == 1) placedblocks[y + mapY][x + mapX] = shape.type + 1;
            }
        }
    }
}


// will probably implement this in the other file 
unsigned int valid_shape_position(int x, int y, shape_t shape, char** placedblocks, unsigned int NUM_ROWS, unsigned int NUM_COLS) {
    for (int mapY = 0; mapY < 4; mapY++) {
        for (int mapX = 0; mapX < 4; mapX++) {
            if (shape.map[mapY][mapX] == 1) { // If a block in the shape is filled...
                if ((y + mapY) < 0 || (y + mapY) > NUM_ROWS) { // 1. Check vertical bounds
                    return 0;
                }

                if ((x + mapX) < -3 || (x + mapX) > NUM_COLS) { // 1. Check horizontal bounds. Note that the bound is -3
                    return 0;                                   // to allow for some shapes
                }

                if (placedblocks[y + mapY][x + mapX] > 0) { // 2. If it is inbounds, check that no block is placed there
                    return 0;
                }
            }
        }
    }

    return 1;
}

color_t get_color(char type) {
    return COLOR[(int)type];
}

shape_t get_next_orientation(shape_t currshape) {
    shape_t nextshape;

    nextshape.type = currshape.type;
    nextshape.color = currshape.color;

    int orientation = currshape.orientation;
    orientation++;

    if (orientation == 4) {
        orientation = 0;
    }

    nextshape.orientation = orientation;

    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            nextshape.map[y][x] = SHAPE[nextshape.type][orientation][y][x];
        }
    }

    return nextshape;

}
