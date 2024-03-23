
#!/bin/bash

create() {
	run=0
	while [ $run ]; do

		pos=1	
		case "$pos" in 
			1) read -p "Department Code (2-3 letters): " -n 3 depCode
			if [[$depCode =~ ^[0-9]{2,3}$]]; then
				echo "$depCode"
				pos=2
			elif [[ -z "$depCode" ]]; then
				echo "CTRL-D was pressed. Exiting..."
				exit 0
			
			else
				echo "invalid input"
			fi
			;;
			2) read -p "Department Name: " depName
			if [[$depName =~ ^[a-z]$]]; then
				pos=3
			elif [[ -z "$depName" ]]; then
				echo "CTRL-D was pressed. Exiting..."
				exit 0
			
			else
				echo "invalid input"
			fi
			;;
			3) read -p "Course Number: " crsNum
			if [[$crsNum =~ ^[0-9]{2,3}$]]; then
				pos=4
			elif [[ -z "$crsNum" ]]; then
				echo "CTRL-D was pressed. Exiting..."
				exit 0
			else
				echo "invalid input"
			fi
			;;
			4) read -p "Course Name: " crsName
			if [[$crsName =~ ^[0-9]{2,3}$]]; then
				pos=5
			elif [[ -z "$crsName" ]]; then
				echo "CTRL-D was pressed. Exiting..."
				exit 0
			
			else
				echo "invalid input"
			fi
			;;
			5) break 
			;;
			*) echo "invalid input: try again"
			;;
		esac
    done
	echo "$depCode $depName $crsNum $crsName"
}
	


