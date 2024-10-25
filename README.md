# Hand Sensor Tetris Project

This project is a unique (and maybe too complex) way to play Tetris. The end result of the project was that the player can play tetris using just their hand! The user is able to control the falling block in tetris using a glove equipped with an accelerometer and transmitted the data to a Raspberry Pi. The game graphics and logic for Tetris were coded in C on the Raspberry Pi. The accelerometer data allowed the user to control the game by wearing the glove. Additionally, we incorporated the game's WAV file to play the theme song during the opening sequence. For instance, if the wearer rapidly moved the glove to the left, the code interpreted the negative acceleration and shifted the falling block to the left.

## Features

- Accelerometer-Controlled Game: Move the Tetris blocks to the left or right by moving your hand.
- Raspberry Pi Integration: Game logic and graphics run on a Raspberry Pi.
- Theme Song: Plays the classic Tetris theme song during the opening sequence.

## Demo Video

In this video, you can see the Hand Sensor Tetris project in action. The glove wearer uses hand movements to control the Tetris falling blocks, demonstrating how the accelerometer data translates into game commands. This demo showcases the innovative control mechanism and the gameplay experience.

[![Hand Sensor Tetris Demo](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349)](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349 "Hand Sensor Tetris Demo Video")

## Credits

- [Raspberry Pi](https://www.raspberrypi.org/)
- [Tetris](https://en.wikipedia.org/wiki/Tetris)
- [Accelerometer](https://en.wikipedia.org/wiki/Accelerometer)
