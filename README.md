# Hand Sensor Tetris Project
 
A probably-too-complex way to play Tetris — using just your hand.
 
The player wears a glove equipped with an accelerometer that transmits motion data to a Raspberry Pi over a wired connection to the Pi's GPIO ports. The Pi runs the full game — rendering, collision detection, block rotation, line clearing — all written in C. Tilt your hand left, the block moves left. Tilt right, it moves right. The accelerometer picks up the directional acceleration and the code maps those values to in-game movement in real time. For example, a rapid leftward hand motion registers as negative acceleration, which shifts the falling block left.
 
The hardware side involved mounting the accelerometer onto a glove and wiring it into the Pi's input pins, then writing the interface layer to read raw acceleration data and convert it into discrete game commands. The game engine itself handles standard Tetris mechanics — piece spawning, gravity, rotation, row completion — rendered directly on a monitor connected to the Pi.
 
We also wired up the classic Tetris theme song (as a `.wav` file) to play during the opening sequence, because what's Tetris without the music. The audio playback is handled through a custom header (`tetris_audio.h`) that manages the WAV file integration.
 
## How It Works
 
- Accelerometer glove reads hand movements and sends data to the Raspberry Pi's GPIO ports
- Game engine in C handles rendering, collision detection, block rotation, and line-clearing logic on the Pi
- Motion mapping interprets raw acceleration values as directional input — rapid hand movement in one direction shifts the falling block accordingly
- Audio module plays the Tetris theme during the opening sequence via WAV file playback
 
## Demo
 
The video below shows the full setup in action — glove movements controlling the falling blocks in real time.


[![Hand Sensor Tetris Demo](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349)](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349 "Hand Sensor Tetris Demo Video")

## Credits

- [Raspberry Pi](https://www.raspberrypi.org/)
- [Tetris](https://en.wikipedia.org/wiki/Tetris)
- [Accelerometer](https://en.wikipedia.org/wiki/Accelerometer)
