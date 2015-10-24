### Welcome to the Java wrapper of SoDA

The aim of the SoDA (Software Development Analysis framework) library, toolset and program repository is to provide researchers and practitioners a framework with which various code coverage-based analyses can be performed in a unified environment, and which can be applied to large programs and test suites efficiently, and without limitations on programming language, granularity and coverage criteria.

The SoDA library contains the necessary data structures to efficiently store a coverage matrix for multiple test cases, the results of your test suite execution of multiple revisions and the changes in your program during multiple revisions. These data structures can be used to implement prioritization or other dependence analysis related algorithms.

Visit our [wiki](https://github.com/sed-szeged/soda/wiki/) page to get more information about the project.

### About SoDA-Java

This project contains Java classes and the corresponding JNI C++ code.

### How to build

Build and package the Java classes:

```bash
mvn clean compile package
```

Build the C++ JNI code

```bash
mkdir build
cd build
cmake ..
make
```
