#!/bin/bash

day=$(date +%A)

echo "Today is: $day"

case $day in
    Monday)
        echo "Start the week with energy and focus!"
        ;;
    Tuesday)
        echo "Keep the momentum going!"
        ;;
    Wednesday)
        echo "Halfway through the week!"
        ;;
    Thursday)
        echo "Stay productive, the weekend is near!"
        ;;
    Friday)
        echo "Finish strong and enjoy your evening!"
        ;;
    Saturday)
        echo "Relax and enjoy your weekend!"
        ;;
    Sunday)
        echo "Rest well and prepare for the new week!"
        ;;
    *)
        echo "Have a great day!"
        ;;
esac