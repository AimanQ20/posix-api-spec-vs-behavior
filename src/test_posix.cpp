#include <iostream>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <cstring>
#include <sys/stat.h>
void print_result(const std::string& test, int result) {
    std::cout << "[" << test << "] ";
    if (result == -1) {
        std::cout << "FAIL | errno=" << errno
                  << " (" << strerror(errno) << ")";
    } else {
        std::cout << "SUCCESS | return=" << result;
    }
    std::cout << std::endl;
}

int main() {
    char buffer[10];

    // Test 1: read() on closed file descriptor
    int fd = open("test.txt", O_CREAT | O_WRONLY, 0644);
    close(fd);
    int r1 = read(fd, buffer, sizeof(buffer));
    print_result("read() on closed fd", r1);

    // Test 2: write() to read-only file
    fd = open("readonly.txt", O_CREAT | O_RDONLY, 0444);
    int r2 = write(fd, "A", 1);
    print_result("write() on read-only fd", r2);
    close(fd);

    // Test 3: read() from empty file
    fd = open("empty.txt", O_CREAT | O_RDONLY, 0644);
    int r3 = read(fd, buffer, sizeof(buffer));
    print_result("read() on empty file", r3);
    close(fd);

    // Test 4: write() zero bytes
    fd = open("zerobyte.txt", O_CREAT | O_WRONLY, 0644);
    int r4 = write(fd, buffer, 0);
    print_result("write() zero bytes", r4);
    close(fd);

    // Test 5: open() without permission 
    int fd_perm = open("noperm.txt", O_CREAT | O_WRONLY, 0644);
    if (fd_perm != -1) {
    close(fd_perm);
    }
    chmod("noperm.txt", 0000);
    int r5 = open("noperm.txt", O_RDONLY);
    print_result("open() without permission", r5);
    return 0;
}
