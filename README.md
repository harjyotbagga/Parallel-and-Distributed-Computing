# Parallel and Distributed Computing
 
This is a companion repository for my Parallel and Distributed Computing class at my University. It contains the codes in the C Programming language, using the OpenMP and MPI library.
 
 
## About
 
**According to Wikipedia:**
 
**[OpenMP](https://www.openmp.org/)** is an application programming interface (API) OpenMP (Open Multi-Processing) supports multi-platform shared memory multiprocessing programming in C, C++, and Fortran, on many platforms, instruction-set architectures and operating systems, including Solaris, AIX, HP-UX, Linux, macOS, and Windows. It consists of a set of compiler directives, library routines, and environment variables that influence run-time behavior.
 
**[Message Passing Interface (MPI)](https://computing.llnl.gov/tutorials/mpi/)** is a standardized and portable message-passing standard designed by a group of researchers from academia and industry to function on a wide variety of parallel computing architectures. The standard defines the syntax and semantics of a core of library routines useful to a wide range of users writing portable message-passing programs in C, C++, and Fortran. There are several well-tested and efficient implementations of MPI, many of which are open-source or in the public domain. These fostered the development of the parallel software industry and encouraged the development of portable and scalable large-scale parallel applications.
 
**TLDR:**
- OpenMP is a way to program on shared memory devices. This means that parallelism occurs where every parallel thread has access to all of your data.
- MPI is a way to program on distributed memory devices. This means that parallelism occurs where every parallel process is working in its own memory space in isolation from the others.
 
 
## Installation Process
Make sure you install the libraries in order to compile and execute the programs. You can install them using the following commands- 
 
**OpenMP**
```
sudo apt-get install libomp-dev
```
**MPI**
```
sudo apt install libopenmpi-dev
sudo apt install openmpi-bin
```
**NOTE:** Make sure you have the gcc compiler to compile and execute the programs. To check
```
gcc --version
```
 
 
## Execute Programs
To compile and execute the programs use the following commands.
 
**OpenMP**
```
gcc <c_program_file_name.c> -fopenmp -o <object_file_name>
./<object_file_name>
 
```
**MPI**
```
mpicc <c_program_file_name.c> -o mpicc <object_file_name>
mpirun -np 2 ./<object_file_name>
```
