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

  [How to install OpenCV](https://linuxize.com/post/how-to-install-opencv-on-ubuntu-20-04/)
### How to compile
Create a build directory in the project folder
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
### How to use

After starting application instructs us what to do next.
When first image is displayed we switch to the next one using any key on the keyboard.
