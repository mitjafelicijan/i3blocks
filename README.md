![Screenshot](https://github.com/mitjafelicijan/i3blocks/assets/296714/c6b68f57-56ce-4007-8264-03698cf0c339)

# i3blocks and some custom scripts

- CPU usage progress bar (requires: mpstat, grep, awk)
- Memory usage progress bar
- Disk usage progress bar
- Nvidia GPU usage progress bar

## Install and use

- C compiler like GCC, Clang or tcc is required.

Clone the repo into `~/.congig/i3blocks`.

```
git clone git@github.com:mitjafelicijan/i3blocks.git ~/.config/i3blocks
cd ~/.config/i3blocks
make
```

And restart i3 with `$mod+shift+r`. That is about it.

I use default fonts for i3 and if you will change to something different your
progress could look better. I just don't care that much about that and it's fine
with me.

> Check https://github.com/vivien/i3blocks-contrib for amazing blocks!
