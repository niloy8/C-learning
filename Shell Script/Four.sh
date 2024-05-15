factorial(){
    fact=1
    for ((i=1; i<=$1; i++)); do
        fact=$((fact*i))
    done
    fact2=1
    for ((j=1; j<=$2; j++)); do
        fact2=$((fact2*j))
    done
    echo "Factorial of $1 is $fact"
    echo "Factorial of $2 is $fact2"
    sum=$((fact+fact2))
    echo "Sum of two factorial is - $sum"
}

read -p "Enter your first number - " number1
read -p "Enter your second number - " number2

factorial $number1 $number2