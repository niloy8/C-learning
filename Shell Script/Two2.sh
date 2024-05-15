read -p "Enter your number " number
declare -a counts
for ((i=0; i<=9; i++)); do
    counts[$i]=0
done


while [ $number -gt 0 ]; do
    digit=$((number % 10))

done