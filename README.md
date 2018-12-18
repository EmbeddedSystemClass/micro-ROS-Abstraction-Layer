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

## How to implement:
### NuttX
You need to copy the source code of the AL ([microROS AL src](https://github.com/microROS/microROS-Abstraction-Layer/tree/master/microrosAL_src/microros_al)) to the library folder of NuttX ([NuttX library folder](https://github.com/microROS/NuttX/tree/master/libs/libc)) and add to the compilation path, doing the next modifications:

- Open the `Makefile`  of the library folder ([Makefile](https://github.com/microROS/NuttX/blob/master/libs/libc/Makefile))
- You must add the next lines:
```
include microros_al/UART/Make.defs
include microros_al/TIMER/Make.defs
include microros_al/SPI/Make.defs
include microros_al/SCHEDULER/Make.defs
include microros_al/I2C/Make.defs
```
Close and save the file.
- Open the libc Kconfig file ([Kconfig](https://github.com/microROS/NuttX/blob/master/libs/libc/Kconfig)) and add the next line:
`source libs/libc/microros_al/Kconfig`
Close and save the file.
- Finally go to the source configuration folder of the Olimex Board ([Olimex-stm32-e407 configs](https://github.com/microROS/NuttX/tree/master/configs/olimex-stm32-e407/src))
- Copy the next files into the the folder:
([GPIO aux files]())
- Overwrite the `Makefile` file.

At this point the source code is already implemented, it only left to implement the headers.

- Copy this folder ([microROS include](https://github.com/microROS/microROS-Abstraction-Layer/tree/master/microrosAL_Inc/microros_al))

### freeRTOS

## How to configure:
### NuttX
### freeRTOS
