# LogWatcher
Utility for research and analysis of log files.
The utility was developed for working with two specific types of logs. Therefore, the characters of the beginning and end of the line are hardcoded.
Used C++, Qt, SQLite

Technical requirements that were followed during development
Part of the study:
1. Can open large log files (up to 3GB)
2. Many search criteria:
Possibility of selection up to 5 occurrences in one line by the condition &.
Up to 10 varieties of string search by condition |.
3. Convenient display of search results - the character of the beginning and end of the line is predefined.
4. Ability to work realtime and offline
5. Possibility of multi-colored lighting for each of the filters

Part of the analysis:
1. Analysis of the log file itself, familiarization with the presence of such logs as INFO, DEBUG, WARNING, and ERROR (.log)
2. A local database is created to store information describing the problem and methods for fixing/circumventing it.
3. The visual output of known problems of problems in the log.

![](https://https://github.com/ZeroCode999/LogWatcher/blob/master/LogWatcher/LogWatcher.png)
