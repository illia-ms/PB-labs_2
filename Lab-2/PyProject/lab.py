from datetime import date
from pickle import dump, load


def read_file(path, header):
    try:
        with open(path, 'rb') as file:
            i = 1
            print('\n' + header)
            try:
                while writing := load(file):
                    print("================================")
                    print("Writing", i)
                    print("Title:", writing.get("title"))
                    print("Writing date:", str(writing.get("day")) + '.' + str(writing.get("month")) + '.'
                          + str(writing.get("year")))
                    if writing.get("publication_year"):
                        print("Publication year:", writing.get("publication_year"))
                    else:
                        print("Writing was not published!")
                    i += 1
            except EOFError:
                print("================================")
    except FileNotFoundError:
        print("File was not found!")


def add_writings(path):
    with open(path, 'ab') as file:
        num = int(input("Enter the number of writings: "))
        for i in range(num):
            print("\nWriting", (i + 1))
            title = input("Title: ")
            date_entry = input("Writing date: ")
            day, month, year = map(int, date_entry.split('.'))
            publication_year = int(input("Publication year: "))
            writing = {"title": title, "day": day, "month": month, "year": year, "publication_year": publication_year}
            dump(writing, file)


def write_new_file(path1, path2):
    with open(path2, 'wb') as new_file:
        with open(path1, 'rb') as old_file:
            cur_date = date.today()
            try:
                while writing := load(old_file):
                    if (cur_date.year - writing.get("year")) < 4:
                        dump(writing, new_file)
                    elif (cur_date.year - writing.get("year")) == 4:
                        if cur_date.month < writing.get("month"):
                            dump(writing, new_file)
                        elif cur_date.month == writing.get("month"):
                            if cur_date.day <= writing.get("day"):
                                dump(writing, new_file)
            except EOFError:
                pass


def show_writings(path):
    try:
        with open(path, 'rb') as file:
            i = 1
            print("\nLate published writings:")
            try:
                while writing := load(file):
                    if (writing.get("publication_year") - writing.get("year")) > 5:
                        print("=================================")
                        print("Writing", i)
                        print("Title:", writing.get("title"))
                        print("Writing date:", str(writing.get("day")) + '.' + str(writing.get("month")) + '.'
                              + str(writing.get("year")))
                        print("Publication year:", writing.get("publication_year"))
                        i += 1
            except EOFError:
                print("=================================")
    except FileNotFoundError:
        print("File was not found!")
