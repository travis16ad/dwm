### What is dwm? Their [website](https://dwm.suckless.org/)
> dwm is an extremely fast, small, and dynamic window manager for X.

### Fonts
I use Symbols Nerd Font (ttf-nerd-fonts-symbols-mono) for some of the tags.
The main font is JetBrains Mono.

### Installation
    # cd to whichever directory you would like to contain the source
    git clone https://github.com/travis16ad/dwm
    cd dwm
    # edit config.h
    # Change the terminal to your terminal. It is currently alacritty.
    # Make any other customizations you want.
    sudo make install

### Features
* [Nord theme](https://www.nordtheme.com/)
* [ru_gaps](https://dwm.suckless.org/patches/ru_gaps/)
* [sticky](https://dwm.suckless.org/patches/sticky/)
* [swallow](https://dwm.suckless.org/patches/swallow/)
* [hide_vacant_tags](https://dwm.suckless.org/patches/hide_vacant_tags/)
* [fancybar](https://dwm.suckless.org/patches/fancybar/)
* [fullscreen](https://dwm.suckless.org/patches/fullscreen/)
* [urgentborder](https://dwm.suckless.org/patches/urgentborder/)
* [pertag](https://dwm.suckless.org/patches/pertag/)
* Partial support for XF86 keys
  * Volume - pactl
  * Brightness - xbacklight
* Screenshot using [Flameshot](https://flameshot.js.org/#/)
* Cool looking Nerd Font icons for the tags
* Launch Firefox, Pavucontrol, Discord Canary, htop, ncspot, and nmtui from keybinds
 * All of these applications have predefined tags
 * Mnemomic keybinds - (b)rowser, (a)udio, (d)iscord, (p)rocess explorer, (m)usic, and (n)etwork

### How do I use this?
Read `config.h` to see the keybinds.
