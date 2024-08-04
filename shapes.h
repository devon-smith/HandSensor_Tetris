#ifndef SHAPES_H
#define SHAPES_H

#include "gl.h"

/* Module to define shapes and their properties. 

Authors: Sebastian Russo <sebrusso@stanford.edu>, 
         Nick Reisner <nreisner@stanford.edu>,
         Devon Smith <devon2@stanford.edu>.

Last Update: 12/7/2022


*/

// struct for shapes, which are 2x4 arrays of 1s and 0s
typedef struct {
    color_t color; // color of shape
    char map[4][4]; // 4x4 array of 1s and 0s
    int type; // 0-6, indicating which shape it is
    int orientation; // 0-3, indicating which orientation it is
} shape_t;

/* 'random_start_shape'

Generates a random shape in the starting orientation.
*/
shape_t random_start_shape(void);

/* 'get_shape'

Obtains a requested shape in a requested orientation.
*/
shape_t get_shape(int requestedshape, int requestedorientation);

/* 'draw_shape_raw'

Draws a shape using raw x and y cords.
*/
void draw_shape_raw(int x, int y, shape_t shape, unsigned int blocksize);

/* 'draw_shape'

Draws a shape.
*/
void draw_shape(int x, int y, shape_t shape);

/* 'clear_shape'

Draws a shape.
*/
void clear_shape(int x, int y, shape_t shape);

/* 'place_shape'

Places a shape into the placedblock array.
*/
void place_shape(int x, int y, shape_t shape, char** placedblocks, unsigned int NUM_ROWS, unsigned int NUM_COLS);

/* 'valid_shape_position'

Returns 1 if a shape is in a valid position (filled parts of the shape are
in bounds and not on placed blocks). Returns 0 if not.
*/
unsigned int valid_shape_position(int x, int y, shape_t shape, char** placedblocks, unsigned int NUM_ROWS, unsigned int NUM_COLS);

/* 'get_color

Used to obtain color of shape type.
*/
color_t get_color(char type);

/* 'get_next_orientation'

Returns the next orientation (clockwise) of the current shape.
*/
shape_t get_next_orientation(shape_t currshape);

/* 'get_next_orientation'

Returns the next orientation (clockwise) of the current shape.
*/
void draw_shadow(int x, shape_t shape, color_t BACKGROUND_COLOR);

void clear_shadow(int x, shape_t shape);
#endif
