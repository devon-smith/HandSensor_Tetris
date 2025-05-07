# Hand Sensor Tetris Project

This project is a unique (and maybe too complex) way to play Tetris. The end result of the project was that the player can play Tetris using just their hand! The user is able to control the falling block in tetris using a glove equipped with an accelerometer and transmits the data to a Raspberry Pi. The game graphics and logic for Tetris were coded in C on the Raspberry Pi. The accelerometer data fed into the raspberry pi allowed the user to control the game by wearing the glove. Additionally, we incorporated the game's theme song in WAV file form to play during the opening sequence. For instance, if the wearer rapidly moved the glove to the left, the code interpreted the negative acceleration and shifted the falling block to the left.

## Features

- Accelerometer-Controlled Game: Move the Tetris block to the left or right by accelerating your hand wearing the glove.
- Raspberry Pi Integration: Game logic and graphics were run on a Raspberry Pi that takes input data from the accelerometer thats attached to ports on the raspberry pi.
- Theme Song: gmae plays the classic Tetris theme song during the opening sequence using wav file.

## Demo Videos

In this video, you can see the Hand Sensor Tetris in action. The glove wearer can use hand movements to control the Tetris's falling block, demonstrating how the accelerometer data translates into game command. This demo shows the control mechanism and the gameplay experience.

[![Hand Sensor Tetris Demo](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349)](https://github.com/user-attachments/assets/2ed877f6-c5f0-4186-aea3-c5e899b5a349 "Hand Sensor Tetris Demo Video")

## Credits

- [Raspberry Pi](https://www.raspberrypi.org/)
- [Tetris](https://en.wikipedia.org/wiki/Tetris)
- [Accelerometer](https://en.wikipedia.org/wiki/Accelerometer)
