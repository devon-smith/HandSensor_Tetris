# Hand Sensor Tetris Project
 
A probably-too-complex way to play Tetris — using just your hand.
 
The player wears a glove equipped with an accelerometer that transmits motion data to a Raspberry Pi. The Pi runs the game logic and graphics, all written in C. Tilt your hand left, the block moves left. Tilt right, it moves right. The accelerometer picks up the directional acceleration and translates it into game commands in real time.
 
We also wired up the classic Tetris theme song (as a `.wav` file) to play during the opening sequence, because what's Tetris without the music.
 
## How It Works
 
- Accelerometer glove reads hand movements and sends data to the Raspberry Pi's GPIO ports
- Game engine in C handles rendering, collision detection, and block rotation on the Pi
- Motion mapping interprets acceleration values as directional input — rapid hand movement in one direction shifts the falling block accordingly
 

Demo
The video below shows the full setup in action — glove movements controlling the falling blocks in real time.

[![Hand Sensor Tetris Demo](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349)](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349 "Hand Sensor Tetris Demo Video")

## Credits

- [Raspberry Pi](https://www.raspberrypi.org/)
- [Tetris](https://en.wikipedia.org/wiki/Tetris)
- [Accelerometer](https://en.wikipedia.org/wiki/Accelerometer)
