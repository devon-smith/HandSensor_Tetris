#ifndef _MY_MODULE_H
#define _MY_MODULE_H

#include "gl.h"
#include "shapes.h"

/* Module to unite the Tetris graphics with the gameplay 
mechanics taking in arm_timer interrupts and ps2_interrupts. 

Authors: Sebastian Russo <sebrusso@stanford.edu>, 
         Nick Reisner <nreisner@stanford.edu>,
         Devon Smith <devon2@stanford.edu>.

Last Update: 12/4/2022


*/

/*
 * Type: `input_fn_t`
 *
 * This typedef gives a nickname to the type of function pointer used as the
 * the shell input function.  A input_fn_t function takes no arguments and
 * returns a value of type unsigned char. `keyboard_read_next` is an example
 * of a possible shell input function.
 */
typedef unsigned char (*input_fn_t)(void);


/* 'screen_copy_buffer'

Copies one fb to the other fb when doublebuffering.
For updating the non-drawn display.
*/
void screen_copy_buffer(char *display, char *draw);

/* 'screen_refresh'

Refreshes the screen by swapping the buffers and calling
screen_copy_buffer to update the non-drawn display.
*/
void screen_refresh(void);

/* 'timer_interrupt'

Handler for arm_timer interrupt events. 
Creates the falling motion of the block 
and calls drawing functions to update screen. 

@param pc: program counter (no current use)
@param aux_data has no current use 
*/
void timer_interrupt(unsigned int pc, void *aux_data);

/* 'graphics_controls_init'

Initializes graphics and controls input.
*/
void graphics_controls_init(input_fn_t read_fn);

/* 'start_screen'

Start screen graphics and waits for key input.
*/
void start_screen(void);

/* 'loss_screen'

Loss screen graphics and waits for key input.
*/
void loss_screen(void);

/* 'get_and_update_next_shape'

Gets a new shape and takes care of graphics for next shape.
*/
void get_and_update_next_shape(void);

/* 'background_init'

Initializes the background of the game. 
*/
void background_init(void);

/* 'score_init'

Initializes the score graphics and backend variables.
*/
void score_init(void);

/* 'next_block_init'

Initializes the next block graphics.
*/
void next_block_init(void);

/* 'placedblocks_init' 

Initializes the array of placed blocks. 
*/
void placedblocks_init(void);

/* 'tetris_init

Initializes placedblocks, background, and controls inputs.
*/
void tetris_init(void);

/* 'draw_square_with_bound'

Draws a block square with a black boundary at the x and y given.
*/
void draw_square_with_bound(int x, int y, int blocksize, color_t color);

/* 'draw_block_once'

Draws a block at the given x and y coordinates in one buffer.
*/
void draw_block_once(unsigned int x, unsigned int y, color_t color);

/* 'draw_block'

Draws a block at the given x and y coordinates in both buffers.
*/
void draw_block(unsigned int x, unsigned int y, color_t color);

/* 'clear_block_once'

Clears a block at the given x and y coordinates in one buffer.
*/
void clear_block_once(unsigned int x, unsigned int y);

/* 'clear_block'

Clears a block at the given x and y coordinates in both buffers.
*/
void clear_block(unsigned int x, unsigned int y);

/* 'read_input'

Manages inputs and adjusts blocks.
*/
void read_input(void);

/* 'tetris_run'

Runs the game.
*/
void tetris_run(void);

/* 'draw_score'

Re-draws the score.
*/
void draw_score(void);

/* 'center_text'

Finds the x value needed to center the given string.
*/
unsigned int center_text(const char *text);

/* 'lowest_spot'

Finds the lowest y position for the current shape in the current x position.
*/
int lowest_spot(void);


#endif
