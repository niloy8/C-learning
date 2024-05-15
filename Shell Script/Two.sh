read -p "Enter the number to see how many times a number occur - " number


declare -a counts

for (( i=0; i<=9; i++ ))
do
    counts[$i]=0
done

while [ $number -gt 0 ]
do
    digit=$((number % 10))
    counts[$digit]=$((counts[$digit] + 1))

    number=$((number / 10))
done
for (( i=0; i<=9; i++ ))
do
    if [ ${counts[$i]} -gt 0 ]; then
        echo "$i = ${counts[$i]} times"
    fi
done