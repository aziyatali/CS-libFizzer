Sanitization is a process of instrumenting memory allocation and accesses to
prevent memory bugs. While AFL can work with a sanitizer, it can lead to
false memory exhaustion bugs - sanitizers allocate a lot of memory. LibFuzzer
natively supports sanitizers, and their usage is recommended.
Unlike AFL, libFuzzer requires some setup. The user needs to write fuzzing
stubs for every interface they want to test. These stubs take random input from
the fuzzer and use it to call the interface being tested. This makes libFuzzer
more versitile than AFL - it can test all functions, not only the ones that parse
files.
