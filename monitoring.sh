#!/bin/bash

x=$(mpstat 1 1| awk 'END{printf("%.0f%%\n", 100 - $NF)}');
echo -n "#Architecture: ";	uname -a;
echo -n "#CPU physical : ";	lscpu | awk 'NR==5{print $NF}';
echo -n "#vCPU : ";		cat /proc/cpuinfo | grep processor | wc -l;
echo -n "#Memory Usage: ";	free --mega | grep Me | awk '{printf("%s/%sMB (%.2f%%)\n", $3, $2, 100*($3/$2))}';
echo -n "#Disk Usage: ";	df --total -m -x tmpfs | awk 'END{
printf("%s/%.0fGb (%.0f%%)\n", $3, $2/1000, 100*$3/$2)}';
echo -n "#CPU load: ";	 	echo ${x};
echo -n "#Last boot: ";		who -b | awk '{print $3 " " $4}';
echo -n "#LVM use: ";		if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi
echo -n "#Connections TCP : "; 	echo -n $(netstat -an | grep ESTABLISHED | wc -l); echo " ESTABLISHED";
echo -n "#User log: ";		who | wc -l;
echo -n "#Network: IP ";	echo -n "$(hostname -I) "; ip link show | grep link/ether | awk '{print $2}';
echo -n "#Sudo : ";		echo "$(journalctl -eq /usr/bin/sudo | grep COMMAND | wc -l) cmd";
