xrdb -merge ~/.Xresources

#xrandr --output VGA-1 --rotation left
#xrandr --output HDMI1 --off

systemctl --user import-environment DISPLAY XAUTHORITY
dbus-update-activation-environment DISPLAY XAUTHORITY

export _JAVA_AWT_WM_NONREPARENTING=1

dunst &
feh --randomize --bg-fill ~/.w &
slstatus 2>&1 >/dev/null &

sleep 2 && exec dwm

#exec i3
