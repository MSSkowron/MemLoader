# MemLoader-Cpp
Simple console app to download and display memes from a popular mem website kwejk.pl

### Technologies
- **Libcurl** used to get website's HTML and download images.
- **OpenCV** used to display images.

### Dependencies
- CMake 3.22 or higher

Make sure to have these libraries installed:
- libcurl
    ```
    $ sudo apt-get install libcurl4-gnutls-dev
    ```
- OpenCV
  
  ```
  $ sudo apt install libopencv-dev python3-opencv
  ```
  
  Verify the installation by importing the cv2 module and printing OpenCV version:
  ```
  $ python3 -c "import cv2; print(cv2.__version__)"
  ```
  If doesn't work try this:

  [How to install OpenCV](https://linuxize.com/post/how-to-install-opencv-on-ubuntu-20-04/)
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
