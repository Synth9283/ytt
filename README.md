# ytt
YouTube Transmitter - A light weight youtube-dl GUI client
## Features
- Cross platform
    - [ ] Support for Windows
    - [ ] Support for MacOS
    - [x] Support for Linux
- User friendly
- Download YouTube videos with ease
- Fast and light weight
- Faster than watching YouTube from a browser
## Compiling
- With make
```
git clone https://github.com/synth9283/ytt.git
cd ytt/
make
```
- If linking fails, try the following
```
git clone https://github.com/synth9283/ytt.git
cd ytt/
make flags="-O3 `pkg-config --cflags --libs gtk3`"
```
