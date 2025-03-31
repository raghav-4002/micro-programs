info = []
link = []

start = None
ptr = None
new = -1


# List creation
list_size = int(input("Enter list size: "))

for i in range(1, list_size + 1):
    new += 1

    if start == None:
        start = new
        ptr = start

    else :
        link[ptr] = new
        ptr = link[ptr]

    item = input(f"Enter item {i}: ")
    info.append(item)
    link.append(None)

#List traversal

print("\nList items are: ")

while start != None:
    print(f"{info[start]}", end=', ')
    start = link[start]