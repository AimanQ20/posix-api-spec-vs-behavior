# POSIX File API Behavior Study

## Motivation
System security mechanisms often rely on assumptions derived from API documentation. 
Inspired by prior research on documentation-driven vulnerability discovery, this project explores whether POSIX file APIs always behave as documented under edge conditions.

## Methodology
We designed a set of lightweight experiments targeting POSIX file-related system calls.
Each test compares documented expectations with observed runtime behavior.

## Findings
Most behaviors align with documentation. However, certain edge cases reveal subtle inconsistencies, such as unexpected errno values returned by write() on read-only file descriptors.

## Security Implications
Documentation-implementation mismatches may lead to incorrect security assumptions in access control, sandboxing, or runtime monitoring systems.

## Future Work
This study can be extended by automating test generation and scaling to additional APIs.

