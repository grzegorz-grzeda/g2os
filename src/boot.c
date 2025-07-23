/*
 * MIT License
 *
 * Copyright (c) 2025 Grzegorz Grzęda
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <stdint.h>
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;
extern uint32_t __data_start__;
extern uint32_t __data_end__;
extern uint32_t __data_load__;
extern uint32_t __stack_end__;

extern int main(void);

void Reset_Handler(void);
void NMI_Handler(void);
void HardFault_Handler(void);
void SVCall_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void Default_Handler(void);

__attribute__((section(".isr_vector"))) void (*const vector_table[])(void) = {
    (void (*)(void))(&__stack_end__),  // stack top
    Reset_Handler,                     // reset handler
    NMI_Handler,                       // NMI Handler
    HardFault_Handler,                 // Hard Fault Handler
    Default_Handler,                   // MemManage
    Default_Handler,                   // BusFault
    Default_Handler,                   // UsageFault
    0,
    0,
    0,
    0,                // Reserved
    SVCall_Handler,   // SVCall
    Default_Handler,  // DebugMonitor
    0,                // Reserved
    PendSV_Handler,   // PendSV
    SysTick_Handler   // SysTick
};

void Reset_Handler(void) {
  uint32_t* bss = &__bss_start__;
  while (bss < &__bss_end__) {
    *bss++ = 0;
  }

  uint32_t* src = &__data_load__;
  uint32_t* dst = &__data_start__;
  while (dst < &__data_end__) {
    *dst++ = *src++;
  }

  main();
  while (1) {
  }
}

void NMI_Handler(void) {
  while (1) {
    // NMI handler code
  }
}

void HardFault_Handler(void) {
  while (1) {
    // Hard fault handler code
  }
}

void SVCall_Handler(void) {
  while (1) {
    // SVCall handler code
  }
}

void PendSV_Handler(void) {
  while (1) {
    // PendSV handler code
  }
}

void SysTick_Handler(void) {
  while (1) {
    // SysTick handler code
  }
}

void Default_Handler(void) {
  while (1) {
    // Default handler code
  }
}