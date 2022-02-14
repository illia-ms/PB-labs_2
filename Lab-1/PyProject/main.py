from files_module import *

path1 = "myFile.txt"
path2 = "newFile.txt"
write_file(path1)
read_file(path1, "Old file:")
write_new_file(path1, path2)
read_file(path2, "New file:")
