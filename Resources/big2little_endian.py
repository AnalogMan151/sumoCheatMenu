#!/usr/bin/python

# Big endian code block assigned as string. Credits to @Nanquitas.
print("Enter the codes:")

lines = []
while True:
    line = raw_input()
    if line:
        lines.append(line)
    else:
        break
code = '\n'.join(lines)


# Strip out the spaces and new lines
code = code.replace(" ","").replace("\n","")

# Initiaing loop variables
big_start = 0
big_end = 8

output =""
size = 0
loop = 0

# Loop through the string 8 characters at a time and convert to little endian
for loop in range(0,(len(code) / 8)):

    bytes = code[big_start:big_end:1]
    decoded_bytes = bytes.decode('hex')
    swap = decoded_bytes[::-1]
    encoded_swap = swap.encode('hex').upper();
    big_start += 8
    big_end += 8

    # Initializes and resets formatting loop
    little_start = 0
    little_end = 2

    # Loops through little endian bytes and formats them '0x00, '
    for i in range(0,4):
        if (size % 8 == 0):
            output += "    "
        output += "0x{}, ".format(encoded_swap[little_start:little_end:1])

        little_start += 2
        little_end += 2
        size += 1
    if (loop % 2 != 0):
        output += "\n"

# Print result minus last comma
print("\n\n")
out = "static const u8 buffer[0x%X] = {\n" % size
out += output[:-3]
out += "\n};\n"
print out

# file = open("output.txt", "w")
# file.write(out)
# file.close()
