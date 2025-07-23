# g2os
My operating system for embedded devices.

## Install tools
You need:
- `cmake`
- `Ninja`
- `arm-none-eabi-gcc`
- `qemu-system-arm`

## Compile and run
1. Clone repository and open directory
2. Generate project `cmake -S . -B build/ -DCMAKE_TOOLCHAIN_FILE=cmake/arm-cortex-m3.toolchain.cmake -GNinja`

    this will create a `build/` directory, based on top level cmake source, for the Ninja build tool. CMake will search for the `arm-none-eabi-gcc` toolchain

3. Compile project `cmake --build build/`
4. Run in QEMU `qemu-system-arm -M lm3s6965evb -kernel build/G2Os -nographic`

    THe LM3S6965EVB is a Stellaris ARM Cortex-M3 emulated chip with emulated 256 kB of Flash, 64 kB of RAM and basic I/O including a UART. We select the `kernel` which is the compiled ELF formatted target file.

5. You should see something like this:
```
$ qemu-system-arm -M lm3s6965evb -kernel build/G2Os -nographic
Timer with period zero, disabling
Hello, World!
```

6. Exit QEMU with `Ctrl+A, X`

## Copyright
Created by Grzegorz Grzęda, 2025 under MIT license