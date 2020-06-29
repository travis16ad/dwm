### What is dwm? Their [website](https://dwm.suckless.org/)
> dwm is an extremely fast, small, and dynamic window manager for X.

### Installation
There is one line that is the bane of my fork's existence

    #include </home/travis/.cache/wal/colors-wal-dwm.h>

It requires pywal to be installed and run simply so it can compile, and it must be edited to match your username. I'm trying to remove this dependency, but it's here for now.

Here is the actual installation process:

    # cd to whichever directory you would like to contain the source
    git clone https://github.com/travis16ad/dwm
    cd dwm
    # edit config.h to use your preferred terminal under rules and termcmd
    # change the wal include statement to match your username
    sudo make install

### Features
* Support for [pywal](https://github.com/dylanaraps/pywal), this [patch](https://github.com/dylanaraps/pywal/files/2751496/wal.patch.zip) from this [thread](https://github.com/dylanaraps/pywal/issues/186)
* [ru_gaps](https://dwm.suckless.org/patches/ru_gaps/)
* [sticky](https://dwm.suckless.org/patches/sticky/)
* [swallow](https://dwm.suckless.org/patches/swallow/)
* [hide_vacant_tags](https://dwm.suckless.org/patches/hide_vacant_tags/)
* Partial support for XF86 keys, allowing volume and brightness control (depends on xbacklight and pactl)
