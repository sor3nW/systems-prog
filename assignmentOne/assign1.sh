

#!/bin/bash
source create.sh
source read.sh
source update.sh
source delete.sh
source update.sh
source enroll.sh
source total.sh

read -p  "
Enter one of the following actions or press CTRL-D to exit.
C - create a new course record
R - read an existing course record
U - update an existing course record
D - delete an existing course record
E - update enrolled student count of existing course
T - show total course count 
"  choice
go=0
while [ $go ]; do
	if [[ -z "$choice" ]]; then
		echo "CTRL-D was pressed. Exiting..."
		exit 0
	fi	
	case "$choice" in 
		C) create
		break
		;;
		R) read
		break
		;;
		U) update
		break
		;;
		D) delete
		break
		;;
		E) udpateEnroll
		break
		;;
		T) total
		break
		;;
		*) read -p "Invalid Input. Try again: " -n 1 choice
		;;
	esac
done

