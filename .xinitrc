xrdb -merge ~/.Xresources

# Video Config
# xrandr --output VGA-1 --rotation left
# xrandr --output HDMI1 --off

# Fix some "Bugs"

systemctl --user import-environment DISPLAY XAUTHORITY
dbus-update-activation-environment DISPLAY XAUTHORITY

export _JAVA_AWT_WM_NONREPARENTING=1

# Wallpaper, status and dunst 
# feh --randomize --bg-fill ~/.w &
slstatus 2>&1 >/dev/null &
xsetroot -solid "#010309"
dunst &

# Start dwm
sleep 1 && exec dwm
