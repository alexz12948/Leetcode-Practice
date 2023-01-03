#!env/bin/python3
'''
Name: Alexander Zsikla
Date: Jan 3rd, 2023

Purpose: Allow me to redo a leetcode post by:

* Finding the folder
* Renaming it to be one more
* Generating the problem again
* Copying over the solution and old post
* Removing new directory

Note: This is not meant to be permanent and will be removed later on
so documentation and error handling is not prevalent in this code!
'''
import os
import sys
import shutil

old_folder = ""
problem_number = int(sys.argv[1])
for _, dirs, _ in os.walk(os.getcwd()):
    for dir in dirs:
        if f'{str(problem_number).zfill(4)}__' in dir:
            old_folder = dir
            break

assert old_folder != "", "Couldn't find problem number"

_, second = old_folder.split('__')
new_folder = 'tmp_solution'
os.rename(old_folder, new_folder)
os.system(f'./gen_lc_folder.py {problem_number}')

shutil.copy(new_folder + '/sol.cpp', old_folder + '/sol.cpp')
shutil.copy(new_folder + '/lc_post.md', old_folder + '/old_post.md')
shutil.rmtree(new_folder, ignore_errors=False)
