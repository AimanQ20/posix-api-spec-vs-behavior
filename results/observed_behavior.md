# Observed POSIX API Behavior

Test 1: read() on closed fd  
Observed: return -1, errno=EBADF  
Matches documentation.

Test 2: write() on read-only fd  
Observed: return -1, errno=EBADF  
Note: Documentation may suggest EACCES; implementation uses EBADF.

Test 3: read() on empty file  
Observed: return 0 (EOF)  
Matches documentation.

Test 4: write() zero bytes  
Observed: return 0  
Matches documentation.

Test 5: open() without permission  
Observed: return -1, errno=EACCES  
Note: Initial attempt returned ENOENT due to missing file; experiment was refined to ensure file existence before permission removal.

