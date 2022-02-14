def read_file(path, header):
    try:
        with open(path) as file:
            print(header)
            print(file.read())
    except FileNotFoundError:
        print("File was not found!")


def write_file(path):
    with open(path, 'a') as file:
        print("Your text:")
        while True:
            s = input()
            if s == '':
                break
            else:
                file.write(s + '\n')


def write_new_file(path1, path2):
    with open(path2, 'w') as new_file:
        with open(path1) as old_file:
            for line in old_file:
                if line.isspace():
                    new_file.write(line)
                else:
                    line = line.lstrip(' ').rstrip(' \n')
                    count = 0
                    for ch in line:
                        if ch == ' ':
                            count += 1
                    line = line.replace(' ', "  ")
                    new_file.write(line + ' - ' + str(count) + '\n')
