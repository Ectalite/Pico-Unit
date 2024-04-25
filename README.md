# Pico-Unit
Simple and lightweight Test-Framework for Raspberry Pi Pico

Example can be compiled with cmake.
Once running on the pico, the programm sends these results every 1000ms:
```
####### Starting tests #######
####### Starting test1 #######
[Test test1] FAILED - Amount is not 42
[Test test1] 0/1 asserts passed
TEST test1 FAILED
####### Starting test2 #######
[Test test2] 1/1 asserts passed
TEST test2 OK
####### Ending tests #######
Total tests: 2
Succeeded tests: 1
Failed tests: 1
```
