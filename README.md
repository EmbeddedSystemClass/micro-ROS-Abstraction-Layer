# microROS-Abstraction-Layer Alpha

This is an abstraction layer (AL) that unifies and simplifies the development of NuttX and freeRTOS for microROS project.
In this version we can use the next features:
- I2C read/write multiple bytes.
- SPI read/write multiple bytes.
- UART read/write and poll to check is new data are available in the bus.
- GPIO read/write.
- Creation of periodic timer and modify the period.
- Creation/delete task.
- Pause a task.
- Modify and get the priority of a running task.

At this moment it's only available for the Olimex-STM32-E407 board, but in the next version will be available for the STM32L1Discovery Board.
