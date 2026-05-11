<!---

This file is used to generate your project datasheet. Please fill in the information below and delete any unused
sections.

You can also include images in this folder and reference them in the markdown. Each image must be less than
512 kb in size, and the combined size of all images must be less than 1 MB.
-->

## How it works

Running Pong in 2 hardware where ball get teleport to your friend computer when pass! You can pass back and forth indefinitely as long as it is physically connected.

How it works is like:

You connected two identical FPGA hardware of the design in the bidirectional pin.
It will join together in the same game, same system by transfering data within each other.
It kind of hack itself to unit and merge to single system run by two different identical fpga design.

Toggle the DIP Pin of pin 1 to move up and pin 2 to move down. Ball will collide will surface and bounce. If it hit the horizontal edge of the screen, if it is connected to another fpga with same design, it will got teleport to it. If no connection provided, it will just served as wall as isolated room.

Toggle pin 8 to determine (ON) Left side id 0 or (Off) Right side id 1
Side is not implemented with distinct feature but as a proof of concept of seperation of identity running at your local FPGA space under same system.

I build it under a week with no prior background for self taught myself all about topics within distributed computing, network protocol, signal processing, hardware and HDL, chip design and game engineering. There is a lot of feature planned but due to lack of experience and time. It serves as bare basics of its functionality which can be implemented hugely on future development. Fun to learn by doing and learn how to come up with the conventional way just from pure thinking. Fun fact the author continuously working on this project for 72 hours just to catch up the tapeout deadline as he learn about TinyTape Out in FOSSi 2026 and want to build up with the promo over active. Not Fun for not eating sleeping and drinking for entire 3 days sitting on computer figuring out subtle bug and unorganized framework and development.

## How to test

Connect to VPA for display in output pmod socket through TinyVGA.
Hook up another fpga with same design with jumper wire or any connection
pin 1 <> pin 2 UART Universal Asynchronous Receiver-Transmitter
pin 2 <> pin 1 UART Universal Asynchronous Receiver-Transmitter
pin 5 <> pin 6 HasBall
pin 6 <> pin 5 HasBall
pin 7 <> pin 8 Sync network check
pin 8 <> pin 7 Sync network check
It run the game as if your component is playing outside of yoru screen.

When it is connected properly, the ball will transfer through your left and right edge of your screen to others opposite edge like a seamlessly connected room. When it disconnected the room will break a part and it will auto detect and spawn a ball back to you as if you are in isolated room. If you got reconnected, the left side (id 0) will keep the ball and the right side (id 1) ball will disappear. You can choose your ID just by toggling DIP Switch in pin 8 (not recommended during game is running).

It serves as a proof of concept of running distributed computing for playing pong,
where data is constantly passing and do operation in your hardware, and then exchange the computed result (like how the ball travel and locate back to your screen).

## External hardware

1. Monitor compatible with VGA
2. TinyVVGA
3. Gamemod controller and other pmod device (Still WiP)