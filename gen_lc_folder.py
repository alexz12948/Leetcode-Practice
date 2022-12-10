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
import re
from markdownify import markdownify
from bs4 import BeautifulSoup, element
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


def lc_directory_exists(lc_problem_num: int) -> bool:
    '''
    lc_directory_exists

    Given a leetcode problem number, determines whether a directory
    already exists for that problem
    '''
    regex = re.compile(re.escape(str(lc_problem_num)) + r'__')
    for _, dirs, _ in os.walk(os.getcwd()):
        for dir in dirs:
            if re.match(regex, dir):
                return True

    return False


def generate_folder(problem_number: int, problem_title: str, problem_md: str, code: str):
    '''
    generate_folder

    Given a problems number, title, prompt, and code generates two files with
    the necessary content and boilerplate for the question
    '''
    problem_dir = f'{problem_number}__{problem_title}'
    os.makedirs(problem_dir)
    with open(f'{problem_dir}/prompt.md', 'w') as file:
        file.write(problem_md)

    with open(f'{problem_dir}/sol.cpp', 'w') as file:
        file.write(code)

    with open(f'{problem_dir}/lc_post.md', 'w') as file:
        file.write('''C++ || Easy to Understand with In-Depth Explanation and Examples || O(TODO)\n
# PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁\n
# Intuition\n\n\n
# Approach\n\n\n
# Complexity

**Time Complexity:** $$O()$$
**Space Complexity:** $$O()$$

# Code

```c++

```

**PLEASE UPVOTE IF YOU FIND MY POST HELPFUL!! 🥺😁**''')


def find_problem_markdown(soup: BeautifulSoup) -> str:
    '''
    find_problem_markdown

    Given a soup, finds the problem's prompt and cleans/returns the string
    '''
    problem: element.Tag = soup.find(
        "div", {"class": "_1l1MA"})
    tmp = markdownify(str(problem)
                      .replace('<sup>', '^')
                      .replace('</sup>', ""))

    ans = []
    for split in ["**Example 1:**", "**Constraints:**", -1]:
        longer = tmp.index(split) if split != -1 else -1
        curr, tmp = tmp[:longer], tmp[longer:]
        ans.append(curr.replace('\n\n\n', '\n\n').rstrip())

    ans[-1] += '\n'
    return '\n\n'.join(ans)


def find_code_snippet(soup: BeautifulSoup) -> str:
    '''
    find_code_snippet

    Given a soup, finds the problem's code and returns it
    '''

    prop_data = soup.find("script", {"id": "__NEXT_DATA__"}).string
    # This removes everything after "envInfo" since it contains characters
    # That weren't able to be parsed. Added in brackets at the end to properly
    # format the json
    code_str = prop_data[:prop_data.index('"envInfo"') - 1]
    code_str += ("}" * 4) + ']' + ("}" * 4)
    queries: dict = json.loads(code_str).get('props').get(
        'pageProps').get('dehydratedState').get('queries')
    code = ''
    for query in queries:
        try:
            code_snippets = query.get('state').get(
                'data').get('question').get('codeSnippets')
            cpp_code_snippet = list(filter(
                lambda lang: lang.get('lang') == 'C++', code_snippets))[0]
            code = cpp_code_snippet.get('code')
            break
        except:
            # This means that there weren't any code snippets in that query
            continue
    else:
        # If the for loop never breaks means we never found the code
        raise ValueError('Could not find code snippet')

    return code


def scrape_prompt(lc_problem_url: str) -> str:
    '''
    scrape_prompt

    Given a leetcode problem url, returns the prompt of that question
    in a markdown format
    '''
    try:
        driver.get(lc_problem_url)
        WebDriverWait(driver, 20).until(
            EC.invisibility_of_element_located((By.ID, "__NEXT_DATA__"))
        )

        html = driver.page_source
        soup = BeautifulSoup(html, 'html.parser')
        return find_problem_markdown(soup), find_code_snippet(soup)
    except Exception as e:
        print('A problem occured\n', e)
        driver.quit()


def main():
    args = parse_args()
    if (args.question_number != -1):
        lc_question_number = args.question_number
    else:
        lc_question_number = int(
            input("Enter the question you are looking for: "))

    if (lc_directory_exists(lc_question_number)):
        print(
            f"Problem: Directory already exists for question number {lc_question_number}")
        return

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
