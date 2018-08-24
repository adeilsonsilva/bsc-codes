#!/bin/bash

lastUser=13
maxUser=5

i=1
while [ $i -le $lastUser ]
	do
	   j=1
	   while [ $j -le $maxUser ]
		   do
				command="./gtruth_save gtruth_images/${i}_${j}.jpg"
				echo $command;
				$command;
				true $((j++))
		   done
	   true $(( i++ ))
	   echo "==========================================================================="
	done
