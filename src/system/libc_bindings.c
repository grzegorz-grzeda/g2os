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
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/times.h>
#include <unistd.h>

#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef S_IFCHR
#define S_IFCHR 0020000  // Character device
#endif

// Type definitions for systems that don't have them
#ifndef _OFF_T_DECLARED
typedef long off_t;
#define _OFF_T_DECLARED
#endif

#ifndef _SSIZE_T_DECLARED
typedef long ssize_t;
#define _SSIZE_T_DECLARED
#endif

extern uint32_t __heap_start__;
extern uint32_t __heap_end__;
static uint32_t heap_ptr = 0;

// External heap management (implemented in heap.c)

void* _sbrk(size_t size) {
    if (heap_ptr == 0) {
        heap_ptr = (uint32_t)&__heap_start__;
    }

    if (heap_ptr + size > (uint32_t)&__heap_end__) {
        return (void*)-1;
    }

    void* ptr = (void*)heap_ptr;
    heap_ptr += size;
    return ptr;
}

// Core system calls
int _close(int fd) {
    // Close file descriptor (not implemented)
    return -1;  // Indicate failure
}

void _exit(int status) {
    // Exit the program - halt the system
    while (1) {
        // Infinite loop to simulate a halt
        __asm__ volatile("wfi");  // Wait for interrupt (power saving)
    }
}

int _fstat(int fd, struct stat* st) {
    // Get file status (not implemented)
    if (st == NULL) {
        errno = EFAULT;
        return -1;
    }
    st->st_mode = S_IFCHR;  // Indicate character device
    return 0;               // Indicate success
}

int _getpid(void) {
    // Get process ID (not implemented)
    return 1;  // Return a dummy process ID
}

int _isatty(int fd) {
    // Check if file descriptor is a terminal
    // For embedded systems, typically stdin/stdout/stderr are TTY
    return (fd >= 0 && fd <= 2) ? 1 : 0;
}

int _kill(int pid, int sig) {
    // Send signal to process (not implemented)
    errno = ENOSYS;
    return -1;
}

off_t _lseek(int fd, off_t offset, int whence) {
    // Seek in file (not implemented)
    errno = ENOSYS;
    return -1;
}

int _open(const char* pathname, int flags, ...) {
    // Open file (not implemented)
    errno = ENOSYS;
    return -1;
}

ssize_t _read(int fd, void* buf, size_t count) {
    // Read from file descriptor (not implemented)
    // For UART input, you would implement this
    errno = ENOSYS;
    return -1;
}

ssize_t _write(int fd, const void* buf, size_t count) {
    // Write to file descriptor
    // For embedded systems, typically redirect to UART
    // This is where you'd implement printf output

    // Example implementation for UART output:
    // if (fd == 1 || fd == 2) {  // stdout or stderr
    //   return uart_write(buf, count);
    // }

    errno = ENOSYS;
    return -1;
}

// Additional file system operations (optional)
int _stat(const char* pathname, struct stat* st) {
    // Get file statistics (not implemented)
    errno = ENOSYS;
    return -1;
}

int _unlink(const char* pathname) {
    // Remove file (not implemented)
    errno = ENOSYS;
    return -1;
}

int _link(const char* oldpath, const char* newpath) {
    // Create hard link (not implemented)
    errno = ENOSYS;
    return -1;
}

// Time functions (optional)
clock_t _times(struct tms* buf) {
    // Get process times (not implemented)
    errno = ENOSYS;
    return -1;
}

int _gettimeofday(struct timeval* tv, struct timezone* tz) {
    // Get current time (not implemented)
    errno = ENOSYS;
    return -1;
}