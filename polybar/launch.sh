#------------------------------------------------------------
# POLYBAR - Status bar
#
# Polybar launch program
#
# accent color for polybar is set in 
# * /etc/init.d/accent_color.sh
# * /bin/accent (present in git repo dotfiles)
#
# Move this file to $HOME/.config/polybar/config
#------------------------------------------------------------
# Author:       Adrien CARBONARO
# Dotfiles :    www.github.com/adriencarbonaro/dotfiles.git
#------------------------------------------------------------

# Terminate already runnning bars
killall -q polybar

# Wait until the processes have been shut down
while pgrep -u $UID -x polybar >/dev/null; do sleep 1; done

# Launch carbo bar
# polybar carbo &

#for m in $(polybar --list-monitors |cut -d":" -f1); do
#	MONITOR=$m polybar --reload carbo &
#done

MONITOR=DP-0 polybar carbo &
MONITOR=DP-2 polybar carbo &
MONITOR=HDMI-0 polybar carbo &
