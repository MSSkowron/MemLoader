# MemLoader-Cpp
Simple app to download and display memes from a popular mem-website kwejk.pl

### Dependencies
- CMake 3.22 or higher

Make sure to have these libraries installed:
- libcurl
    ```
    sudo apt-get install libcurl4-gnutls-dev
    ```
- OpenCV

  [How to install OpenCV](https://medium.com/@pokhrelsuruchi/setting-up-opencv-for-python-and-c-in-ubuntu-20-04-6b0331e37437)
### How to compile
Create a build directory
```
mkdir build
```
Go inside
```
cd build
```
Run cmake and point to the parent directory
```
cmake ..
```
Run make
```
make
```
Run program
```
./MemLoader-cpp
```
