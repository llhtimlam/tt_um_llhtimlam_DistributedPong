<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## How it works

Left chip controls the left half of the screen

Right chip controls the right half of the screen

When the ball reaches the screen boundary, the chip passes it to the other chip

The other chip continues the game on its half

What Happens When You Connect Two Chips
Connected: Ball travels seamlessly from one screen to the other

Disconnected: Each chip becomes its own isolated game (ball bounces off the edge like a wall)

Reconnected: The left chip keeps the ball, the right chip deletes its ball and waits for the ball to pass.

**The Distributed Computing Magic**

The chips don't just pass the ball blindly - they do a handshake to pass the ball's position and speed through the bidirectional pin with a communication protocol.
So when the ball reaches to the edge of the screen, it got detected and hold the ball in place.
It records the ball physics while holding it and send a message to another chip.
If it fails to pass, it just hold until it receive, if it got disconnected, it resumes and bounces the ball as the portal collapse.
When the another chip got the message, it sends back a roger to complete the handshake move.
It renders the ball and resumes its physics in its own screen.
After sending the ball and received a rodger, it deletes the ball as the another chip got the ball.

It continues moving in the same direction at the same speed, as if the screens were actually stitched to one big continuous playing field.

## How to Test

### Hardware Setup

1. Connect VGA display to the output PMOD socket through **TinyVGA**
2. Hook up another FPGA with the same design using jumper wires:

| Connection | Left Pin | Right Pin | Function |
|------------|----------|-----------|----------|
| UART TX/RX | Pin 1 | Pin 2 | Data transfer |
| UART RX/TX | Pin 2 | Pin 1 | Data transfer |
| Ball ownership | Pin 5 | Pin 6 | Who has the ball |
| Ball ownership | Pin 6 | Pin 5 | Who has the ball |
| Sync network | Pin 7 | Pin 8 | Sync signal |
| Sync network | Pin 8 | Pin 7 | Sync signal |
| Ground | GND | GND | Common reference |

> **Optimization Note:** Connections can be reconfigured to support 4 pairs of Universal Asynchronous Receiver-Transmitter (UART) using the communication protocol framework built for this project. This enables scalable multi-chip networks. (WiP)

### Game Behavior

| Condition | Behavior |
|-----------|----------|
| **Connected properly** | Ball transfers through left/right edges to the other screen like a seamlessly connected room |
| **Disconnected** | Room breaks apart. Auto-detects and spawns a ball on your side as an isolated room |
| **Reconnected** | Left side (ID 0) keeps the ball. Right side (ID 1) ball disappears |
| **Choose your ID** | Toggle DIP switch on pin 8 (not recommended while game is running) |

### Why This Matters

This is a **proof of concept** for distributed computing: data constantly passes between chips, each performing operations on its hardware, exchanging computed results – exactly how the ball travels and locates back to your screen.

---

## External Hardware

| Component | Status |
|-----------|--------|
| Monitor compatible with VGA | Required |
| TinyVGA | Required |
| Gamemod controller | Work in Progress |
| Other PMOD devices | Work in Progress |
