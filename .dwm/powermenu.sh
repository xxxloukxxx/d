#!/bin/bash

function powermenu {
    options="Shutdown\nReboot\nLock"
    selected=$(echo -e $options | dmenu -b -i)

    if [[ $selected = "Shutdown" ]]; then sudo poweroff
    elif [[ $selected = "Reboot" ]]; then sudo reboot
    elif [[ $selected = "Lock" ]]; then slock
    fi
}

powermenu

