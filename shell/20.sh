#KISHAN RANA GHOSH; 20.sh; 19/07/2026
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
        echo "Finish strong and enjoy  evening!"
        ;;
    Saturday)
        echo "enjoy weekend with tea and code!"
        ;;
    Sunday)
        echo "work on startup"
        ;;
    *)
        echo "Have a great day!"
        ;;
esac