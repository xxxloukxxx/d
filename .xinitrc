xrdb -merge ~/.Xresources

#xrandr --output VGA-1 --rotation left

systemctl --user import-environment DISPLAY XAUTHORITY
dbus-update-activation-environment DISPLAY XAUTHORITY

export _JAVA_AWT_WM_NONREPARENTING=1

feh --randomize --bg-fill ~/.w &
slstatus 2>&1 >/dev/null &
exec dwm
