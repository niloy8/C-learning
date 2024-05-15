find_2nd_3rd_highest() {
    max1=0
    max2=0
    max3=0

    for num in "${numbers[@]}"; do
        if ((num > max1)); then
            max3=$max2
            max2=$max1
            max1=$num
        elif ((num > max2 && num < max1)); then
            max3=$max2
            max2=$num
        elif ((num > max3 && num < max2)); then
            max3=$num
        fi
    done
}

read -p "Enter the number of elements: " n

declare -a numbers

for ((i=0; i<n; i++)); do
    read -p "Enter the number: " num
    numbers+=($num)
done

find_2nd_3rd_highest

echo "sum of 2nd and 3rd highest number: $((max2+max3))"
