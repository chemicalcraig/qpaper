# qpaper
Scientific project citation manager

QPaper is a Qt-based GUI for keeping track of references based on topics or manuscripts in preparation. It can export to the bibtex format.
It uses a hard coded bib key format of LAST_AUTHORS_LAST_NAME+YEAR:PAGE, so that the key for a paper by Jane Smith and John Doe
in 2012, appearing on page 1234 of some journal would be formatted "Doe12:1234". This system minimizes the chance of duplicate
entries and has worked for me so far.
There are some bugs, but the basic functions work. Books and Chapters have worked for me so far. Sub-projects probably won't 
work at the moment. 
QPaper is for linux with sane Qt 4 installations. Feel free to port it to other platforms.
