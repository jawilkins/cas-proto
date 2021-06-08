# A Computer Algebra System Prototype Written in C++ #

This repo contains my first experiments with creating a computer algebra system in mid-May 2009 and it was written in C++98. It is based on the Composite design pattern, reference counting, simple rewriting rules, and the use of an extended character set (code page 437)

It is not complete at all and serves more as a demonstration of how awkward I found C++ before C++11 than it does as an algebra system.  But still, I've revived it here because these ideas have been on my mind ever since then and I want to revisit them. (As I write this it is June 8th, 2021)

My plan is to first do my best to write the system in C++98 as a classic object-oriented system. I want to complete the system as I originally envisioned it so I can contrast it with how much differently I would approach this in 2021 with C++20.

### How would you get set up? ###

If it looks like I am goig overboard for a toy project it is because I am. My intent is to learn how to use various C++ analysis tools as well as continuous integration and continue to improve my skill at using version control, build systems, and portable code that can be built across multiple compilers and tools. This doesn't even mention writing for package managers, documentation, and dynamic analysis like fuzzing and detecting memory leaks.

This project is meant to slot into a much larger body of code, but I am working on ways to reduce dependencies and make it possible to pull code out and reuse it without requiring a user to pull all of these dependencies out with it like how a lollipop pulls up the contents of a movie theater floor after you drop it.

This will be largely due to how I slice up the code and also due to techniques like dependency injection and just designing the code to be easily composible so it does not have to live in the same repository as the code it is designed to work well with.

All that is just a long winded way of saying that I hope you can just check out the repo and get up and running using CMake without much fuss.  It you have to do much more than that then I have failed.

It is too soon to actually talk about the CAS, so I have written this here as a placeholder and rough reminder of my goals.

There will be several [examples](examples/README.md) written as I extend the system. 

### Contribution guidelines ###

Pull requests are welcome.

### Who do I talk to? ###

[Jayna A. Wilkins](mailto://Jayna.A.Wilkins@gmail.com)