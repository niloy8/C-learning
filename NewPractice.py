# x =5
# y = "json"
# print(x,y)

# x = 5
# x = "salary"
# print(x)

# x = str(3) # x will be ’3’
# y = int(3) # y will be 3
# z = float(3)
# print(x,"\n",y,z)

# x = 5
# print(type(x))

# a = 4
# A = "salary"
# print(a)

#Assign multiple values
# x,y,z ="orrange","\nbannana\n","cherry"
# print(x,y,z)

# a = b= x = "orrange"

# print(x)

#If you have a collection of values in a list, tuple, etc. Python allows you to extract the values into variables.
#This is called unpacking.
fruits = ['apple','orange','mango']
a,b,c= fruits
print(b)


print(5,a)

x= 'awesome'

def fun():
    print('python is ',x)

fun()


# To create a global variable inside a function, you can use the global keyword.
# Also, use the global keyword if you want to change a global variable inside a function.
x = 10
def fun():
    global x
    x = 20
    print(x)

fun()
print(x)

#bit wise X-or Sets each bit to 1 if only one of two bits is 1
x = 5
x^=3
print(x)
# Python Identity Operators is isnot
y = 7
if x is not y:
    print('hm')
else:
    print('no')

# Python Membership Operators
fruits = ["apple", "banana", "cherry"]
print("banana" in fruits)   # Output: True
print("grape" not in fruits) # Output: True

for value in range(2,5):
    print(value)

# Increment the sequence with 3 (default is 1):
for i in range(2, 20, 3):
    print(i)

# a = "orrange"

# for value in a:
#     print(value)

i = 1
while i < 5:
 print(i)
 if i == 2:
    break
 i += 1

 #find the sum
 numbers = {10, 5, 8, 3, 12, 7}

even_sum = sum(num for num in numbers if num % 2 == 0)
odd_sum = sum(num for num in numbers if num % 2 != 0)

print("Sum of even numbers:", even_sum)
print("Sum of odd numbers:", odd_sum)


numbers = {10, 5, 8, 3, 12, 7}

even_sum = 0
odd_sum = 0

for num in numbers:
    if num % 2 == 0:
        even_sum += num
    else:
        odd_sum += num

print("Sum of even numbers:", even_sum)
print("Sum of odd numbers:", odd_sum)

#second highest number
numbers = {10, 5, 8, 3, 12, 7}

highest = max(numbers)
numbers.remove(highest)
second_highest = max(numbers)

print("Second highest number:", second_highest)

#factorial
num = int(input("Enter a number: "))
factorial = 1

for i in range(1, num + 1):
    factorial *= i

print("Factorial of", num, "is:", factorial)

#fibonacci
n = int(input("Enter the number of terms: "))

a, b = 0, 1

print("Fibonacci Series:", end=" ")
for _ in range(n):
    print(a, end=" ")
    temp = a
    a = b
    b = temp + b
