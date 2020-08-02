### What is dwm? Their [website](https://dwm.suckless.org/)
> dwm is an extremely fast, small, and dynamic window manager for X.

### Installation
This is a line from [config.h](config.h). Install and run pywal before you begin so that dwm can compile

    #include </home/travis/.cache/wal/colors-wal-dwm.h>

Here is the actual installation process:

    # cd to whichever directory you would like to contain the source
    git clone https://github.com/travis16ad/dwm
    cd dwm
    # edit config.h
    # First, change the pywal include line shown above to match your username. It is currently travis.
    # Second, set your preferred font (use monospace if unsure). It is currently JetBrains Mono.
    # Third, change the terminal to your terminal. It is currently alacritty.
    # Finally, make any other customizations you want.
    sudo make install

### Features
* Support for [pywal](https://github.com/dylanaraps/pywal)
* [ru_gaps](https://dwm.suckless.org/patches/ru_gaps/)
* [sticky](https://dwm.suckless.org/patches/sticky/)
* [swallow](https://dwm.suckless.org/patches/swallow/)
* [hide_vacant_tags](https://dwm.suckless.org/patches/hide_vacant_tags/)
* [fancybar](https://dwm.suckless.org/patches/fancybar/)
* [fullscreen](https://dwm.suckless.org/patches/fullscreen/)
* Partial support for XF86 keys
  * Volume - pactl
  * Brightness - xbacklight
* Screenshot to PNG file using maim

### How do I use this?
Read `config.h` to see the keybinds.
