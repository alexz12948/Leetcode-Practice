#!env/bin/python3
'''
Name: Alex Zsikla
Date: Nov 13, 2022

Generates a new folder containing two files:
* sol.cpp - Contains the solution for a particular problem
* prompt.md - Contains the prompt from the question itself

How to Run
`./gen_lc_folder.py` and when prompted, enter the number of the question
that you are working on from leetcode
'''
import argparse
import os
import requests
import json
from markdownify import markdownify
from bs4 import BeautifulSoup
from selenium import webdriver

from selenium.webdriver.chrome.options import Options
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome.service import Service as ChromeService
from selenium.webdriver.common.by import By
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver.support.ui import WebDriverWait

ALGORITHMS_ENDPOINT_URL = "https://leetcode.com/api/problems/algorithms/"
ALGORITHMS_BASE_URL = "https://leetcode.com/problems/"

options = Options()
options.headless = True
options.log_level = 3
driver = webdriver.Chrome(service=ChromeService(
    ChromeDriverManager().install()), options=options)


def generate_folder(problem_number: int, problem_title: str, problem_md: str, code: str):
    '''
    generate_folder

    Given a problems number, title, prompt, and code generates two files with
    the necessary content and boilerplate for the question
    '''
    problem_dir = f'{problem_number}__{problem_title}'
    if (os.path.isdir(problem_dir)):
        print("Problem directory already exists")
        return

    os.makedirs(problem_dir)
    with open(f'{problem_dir}/prompt.md', 'w') as file:
        file.write(problem_md)

    with open(f'{problem_dir}/sol.cpp', 'w') as file:
        file.write(code)

    with open(f'{problem_dir}/lc_post.md', 'w') as file:
        file.write('''Title: C++ || Easy to Understand with Explanation
Tags: cpp, c++, easy-understanding, clean code\n
**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!!** 🥺😁\n
### Intuition\n\n\n
### Approach\n\n\n
### Complexity

**Time Complexity:** O()
**Space Complexity:** O()

### Code

```c++

```''')


def scrape_prompt(lc_problem_url: str) -> str:
    '''
    scrape_prompt

    Given a leetcode problem url, returns the prompt of that question
    in a markdown format
    '''
    try:
        driver.get(lc_problem_url)
        WebDriverWait(driver, 20).until(
            EC.invisibility_of_element_located((By.ID, "initial-loading"))
        )
        html = driver.page_source
        soup = BeautifulSoup(html, 'html.parser')
        problem = soup.find(
            "div", {"class": "content__u3I1 question-content__JfgR"})
        code = soup.findAll(
            "pre", {"class": "CodeMirror-line", "role": "presentation"})
        code_text = ""
        for tag in code:
            # Replaces all non-breaking spaces with spaces
            code_text += tag.get_text().replace("\u00A0", ' ') + '\n'
        return markdownify(str(problem)), code_text
    except Exception as e:
        print('A problem occured\n' + e)
        driver.quit()


def parse_args() -> argparse.Namespace:
    '''
    parse_args

    Responsible for parsing the arguments from the command line
    '''
    parser = argparse.ArgumentParser(
        prog='Generate Leetcode Folder',
        description=('This program automatically generates a folder with the '
                     'c++ code and question prompt')
    )

    parser.add_argument('question_number', type=int, nargs='?',
                        default=-1, help='The leetcode question you are looking for')

    return parser.parse_args()


def main():
    args = parse_args()
    if (args.question_number != -1):
        lc_question_number = args.question_number
    else:
        lc_question_number = int(
            input("Enter the question you are looking for: "))

    algorithms_problems_json = json.loads(
        requests.get(ALGORITHMS_ENDPOINT_URL).content)

    for problem in algorithms_problems_json["stat_status_pairs"]:
        if problem["stat"]["frontend_question_id"] == lc_question_number:
            question_title_slug = problem["stat"]["question__title_slug"]
            url = ALGORITHMS_BASE_URL + question_title_slug
            problem_md, code_text = scrape_prompt(url)
            generate_folder(lc_question_number,
                            question_title_slug, problem_md, code_text)


if __name__ == "__main__":
    main()
    exit(0)
