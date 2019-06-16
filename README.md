# compro
app for competitive programming

## filesystem

```
.
├── app (application using python)
├── atcoder (problems-set folders for atcoder)
├── lib
│   ├── src (library file *.hpp)
│   └── test (tests for library files using gtest)
├── README.md (this file)
└── samplesite 
    └── sampleset

./samplesite/sampleset
├── a (problem name)
│   ├── random
│   │   ├── format.json (to generate random input)
│   │   ├── in
│   │   └── tester.cpp (naive solution for this problem)
│   ├── sample (sample I/O file got from site)
│   │   ├── in
│   │   └── out
│   └── solve.cpp (file to execute and submit)
└── (folder for other problems...)
```

## library

some libraries written in C++14

- bitwise
    - popcnt, msb, lsb
- fp
    - finite field of order p
    - `constexpr` factorial, power
- graph
    - graph algorithms for `std::vector<std::vector<Edge>>`
- segtree
    - lazy segment tree (sum, max, min)
- unionfind
    - union-find tree (order α(n))

tests can execute as following:
```
mkdir build
cd build
cmake ..
make
./test.out
```

## environment

This library assumes to run in following environment:

- Windows 10
- WSL (Ubuntu 16.04)
- Visual Studio Code
- C++14, python3, pylint
- cmake, gtest (for test library files)
- python packages
    - beautifulsoup4
    - requests


## build and debug

- build : `ctrl+shift+b`
    - execute file of `solve.cpp` is `build/solve.out`

## for AtCoder

### login

write down username and password in `.secret/atcoder_login.json`.

```json
{
    "username": "{{your username}}",
    "password": "{{your password}}"
}
```