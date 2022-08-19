#!/bin/bash

echo -n "#Architecture: ";	uname -a;
echo -n "#CPU physical : ";	lscpu | awk 'NR==5{print $NF}';
echo -n "#vCPU : ";		cat /proc/cpuinfo | grep processor | wc -l;
echo -n "#Memory Usage: ";	free --mega | grep Me | awk '{printf("%s/%sMB (%.2f%%)\n", $3, $2, 100*($3/$2))}';
echo -n "#Disk Usage: ";	df --total -m -x tmpfs | awk 'END{
printf("%s/%.0fGb (%.0f%%)\n", $3, $2/1000, 100*$3/$2)}';
