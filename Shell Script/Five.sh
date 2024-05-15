read -p "Enter your word - " input_string
alphabets=0
digits=0
special_chars=0

for ((i=0; i<${#input_string}; i++)); do
    char=${input_string:$i:1}
    if [[ $char == [a-zA-Z] ]]; then
        ((alphabets++))
    elif [[ $char == [0-9] ]]; then
        ((digits++))
    else
        ((special_chars++))
    fi
done

echo "Alphabets = $alphabets"
echo "Digits = $digits"
echo "Special characters = $special_chars"