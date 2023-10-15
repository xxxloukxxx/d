#!/bin/bash

function powermenu {
    options="Shutdown\nReboot\nLock"
    selected=$(echo -e $options | dmenu -i -fn "Hack:size=14")

    if [[ $selected = "Shutdown" ]]; then sudo poweroff
    elif [[ $selected = "Reboot" ]]; then sudo reboot
    elif [[ $selected = "Lock" ]]; then slock
    fi

}

powermenu

