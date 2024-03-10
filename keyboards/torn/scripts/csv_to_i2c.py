input_file = '32x128_lcd.csv'
output_file = '32x128_lcd.i2c'
width = 128
height = 32

# Read the CSV file
def read_csv(input_file):
    ds = []
    with open(input_file, 'r', encoding='utf-8-sig') as file:
        for line in file:
            ds_l = []
            v = ''
            print(line)
            for c in line:
                if c == ',' or c == '\n':
                    if v != '':
                        ds_l.append(int(v))
                        v = ''
                    else:
                        ds_l.append(0)
                else:
                    v += c
            ds.append(ds_l)
    return ds

# Convert the CSV data to I2C data
def ds_to_i2c(ds, width, height):
    i2c = []
    for Y in range(0, height//8):
        for X in range(0, width):
            data = 0
            for y in range(7, -1, -1):
                data = data << 1
                data = data | ds[Y*8+y][X]
            i2c.append(data)
    return i2c

# Write the I2C data to a file
def write_i2c(output_file, i2c):
    with open(output_file, 'w') as file:
        for i, data in enumerate(i2c):
            file.write('0x{:02x}'.format(data))
            if i < len(i2c)-1:
                file.write(', ')
            if i % 16 == 15:
                file.write('\n')


ds = read_csv(input_file)
i2c = ds_to_i2c(ds, width, height)
write_i2c(output_file, i2c)

