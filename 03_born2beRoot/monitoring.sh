#!/bin/bash

printf "#Architecture : "
uname -a

printf "#CPU physical : "
nproc --all

printf "#vCPU : "
cat ../proc/cpuinfo | grep processor | awk '{printf $3}'
printf "\n"

printf "#Memory Usage : "
free -m | grep -w "Mem" | awk '{printf "%d/%dMB (%.2f%%)\n", $3, $2, $3/$2 * 100}'

printf "#Disk Usage : "
df -a -BM | grep "/dev/mapper/" | awk '{use = use + $3}END{print use}' | tr -d '\n'
printf "/"
df -a -BM | grep "/dev/mapper/" | awk '{total = total + $4}END{print total}' | tr -d '\n'
printf "MB ("
df -a -BM | grep "/dev/mapper/" | awk '{use = use + $3; total = total + $4}END{printf "%d", use / total * 100}' | tr -d '\n'
printf "%%)\n"

printf "#CPU load : "
mpstat | grep "all" | awk '{printf "%.2f%%\n", 100-$13}'

printf "#Last boot : "
who -b | awk '{printf $3" "$4" "$5"\n"}'

printf "#LVM use : "
if [ "$(lsblk | grep lvm | wc -l)" -gt 0 ]; then printf "yes\n"; else printf "no\n"; fi

printf "#Connections TCP : "
ss | grep -i tcp | wc -l | tr -d '\n'
printf " ESTABLISHED\n"

printf "#User log : "
who | wc -l

printf "#Network : IP "
hostname -I | tr -d '\n'
printf "("
ip link show | awk '$1 == "link/ether" {print $2}' | sed '2, $d' | tr -d '\n'
printf ")\n"

printf "#Sudo : "
journalctl _COMM=sudo | wc -l | tr -d '\n'
printf " cmd\n"
