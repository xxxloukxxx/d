#xrandr --output VGA-1 --rotation left

systemctl --user import-environment DISPLAY XAUTHORITY
dbus-update-activation-environment DISPLAY XAUTHORITY

feh --randomize --bg-fill ~/.w &
dwmstatus 2>&1 >/dev/null &
exec dwm
