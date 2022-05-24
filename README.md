# Knikkersorteermachine
## Table of contents
- [Knikkersorteermachine](#knikkersorteermachine)
  - [Table of contents](#table-of-contents)
  - [Get started](#get-started)
  - [Example](#example)
  - [Author](#author)

## Get started
First, install the `knikkersorteermachine` library. You can do this using `pip install knikkersorteermachine` or `pip3 install knikkersorteermachine`.  
Next, install the dependencies. You can do this using `pip install pyserial` or `pip3 install pyserial`.  
Now you can create a new Python file. Import the `KnikkerSorteerMachine` from `knikkersorteermachine`.  
Open a new serial connection using pyserial. The parameters for this connection depend on your operating system. The **baudrate** of the machine is `115200`.
Create a new instance of `KnikkerSorteerMachine` with parameter `serial` as the open instance of your serial connection.
You can now start calling methods on the instance.

## Example
```python
import time
import serial
from logging import DEBUG
from knikkersorteermachine import KnikkerSorteerMachine

with serial.Serial(port='/dev/ttyACM0', baudrate=115200, timeout=0) as port:
    machine = KnikkerSorteerMachine(serial=port, log_level=DEBUG)

    chute_pos = 0
    while True:
        # Move the chute to one of the lanes
        machine.move_chute(chute_pos)

        # Increment the chute position for the next move
        chute_pos += 1
        if chute_pos > 6:
            chute_pos = 0

        # Wait 200ms to let the chute move
        time.sleep(0.2)

        # Feed one marble down the chute
        machine.feed_one()

        # Wait 1000ms for the next loop
        time.sleep(1)

```

## Author
Jonas Claes <[jonas@jonasclaes.be](mailto:jonas@jonasclaes.be)>
