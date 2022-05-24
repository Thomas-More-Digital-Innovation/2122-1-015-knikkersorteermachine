import time
import serial
from logging import DEBUG
from knikkersorteermachine import KnikkerSorteerMachine

with serial.Serial(port='/dev/ttyACM0', baudrate=115200, timeout=0) as port:
    interface = KnikkerSorteerMachine(serial=port, log_level=DEBUG)

    chute_pos = 0

    interface.move_chute(0)

    while True:
        # print(f'Sending pos: {chute_pos}')
        # port.write(bytearray([1, chute_pos]))

        # chute_pos += 1
        # if chute_pos > 6:
        #     chute_pos = 0

        # interface.feed_one()

        time.sleep(1)
