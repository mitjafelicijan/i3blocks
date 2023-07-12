![Screenshot](https://github.com/mitjafelicijan/i3blocks/assets/296714/c6b68f57-56ce-4007-8264-03698cf0c339)

# i3blocks and some custom scripts

- CPU usage progress bar (requires: mpstat, grep, awk)
- Memory usage progress bar (requires: free, grep, awk)
- Disk usage progress bar (requires: df, awk, sed)
- Nvidia GPU usage progress bar

> If used percentage for a resource is bellow 10% then no bars will be
> displayed!

## Install and use

- C compiler like GCC, Clang or tcc is required.

Clone the repo into `~/.config/i3blocks`.

```
git clone git@github.com:mitjafelicijan/i3blocks.git ~/.config/i3blocks
cd ~/.config/i3blocks
make

# Before doing this check config_sample and be sure
# you don't overwrite your existing config file.
cp config_sample config
```

And restart i3 with `$mod+shift+r`. That is about it.

Each command takes two **optional** arguments:

- `-w 10` - width of the progress bar (default 10)
- `-p 1` - if 1 then it also prints percentage label (default 0)

Example usage of these arguments:

```bash
./cpu				# will display 10 bars and no percentage label
./cpu -w 20			# will display 20 bars and no percentage label
./cpu -w 20 -p 0	# will display 20 bars and no percentage label
./cpu -w 10 -p 1	# will display 10 bars and percentage label
```

I use default fonts for i3 and if you will change to something different your
progress could look better. I just don't care that much about that and it's fine
with me.

> Check https://github.com/vivien/i3blocks-contrib for amazing blocks!
