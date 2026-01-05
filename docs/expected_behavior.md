# Expected POSIX File API Behavior

This document summarizes expected behaviors based on POSIX documentation.

1. read() on a closed file descriptor
Expected: read() should return -1 and set errno to EBADF.

2. write() to a file opened with O_RDONLY
Expected: write() should return -1 and set errno to EBADF or EACCES.

3. read() on an empty file
Expected: read() should return 0 indicating EOF.

4. write() with count = 0
Expected: write() should return 0 and perform no operation.

5. open() on a file without permissions
Expected: open() should return -1 and set errno to EACCES.
