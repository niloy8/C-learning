read -p "Enter your Number - " number

for ((i = 0; i < ${#number}; i++))
do
if (((i+1) % 2 == 1)); then
digit=${number:i:1}
 echo "$digit is an Odd Positioned Number"
    fi
done
