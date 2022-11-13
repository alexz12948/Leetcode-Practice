# Leetcode Practice

This repository is meant to keep me on track for practicing leetcode questions and was an interesting scripting project for autogeneration

**Note to reader/repo stalker** I am not writing the most clean/legible code since this either comes from coding competitions or just for my own practice. Also note that my solutions that I come up with are most likely not the most efficient

## Background

I started getting interested in becoming a competitive programmer during the spring semester when COVID hit. The main problem was that I was significantly behind other programmers in terms of knowledge of problems and solving techniques. Additionally, school and other extra curriculars made it harder to put time into this project. BUT NO LONGER

I wrote a script that automatically generates a new folder and some resources that will be helpful for remembering problems

## Setup

I used a virtual environment since it is the easiest thing to use for your own machine, but feel free to use whatever makes sense for you. Here is an [article](https://www.freecodecamp.org/news/how-to-setup-virtual-environments-in-python/) that could be useful in getting started with virtual environments

1. Run `pip install -r requirements.txt` to download all of the packages necessary
2. Run `./gen_lc_folder.py` to run the generation framework
   * If this doesn't work and gives you a permission error, run `chmod 700 gen_lc_folder.py` to allow the file to be executable by you
3. Enter the name of the question you are looking at to have its information pulled

## Resources Utilized

* [Bishalsarang GitHub Repo](https://github.com/Bishalsarang/Leetcode-Questions-Scraper) - Helped with inspiration for the scrapper that I wrote
* [Selenium Documentation](https://www.selenium.dev/documentation/webdriver/)
* [Web Scraping Tutorial](https://oxylabs.io/blog/python-web-scraping) - To remember how to use bs4