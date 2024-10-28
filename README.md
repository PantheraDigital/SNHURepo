# SNHURepo
cpp - contains working code of program to load and display class data from a CSV
pdf - pseudocode and analysis of run-time performance for program

## What was the problem you were solving in the projects for this course?
1. Print a list of all the computer science courses in alphanumeric order.
2. For a given course, print out its title and prerequisites.
## How did you approach the problem? Consider why data structures are important to understand.
First I chose a data structure to build the program on that would hold all the data of the classes. I chose to use a Hash Table as I found the average search time of O(1), and the worst case of O(n), to be ideal for this situation as the program would be primarily used to retrieve the data of a class. Second to this the program would be loading the data from a file so the average insertion time of O(1), and the worst case of O(n), were a good fit for this as well since the other proposed data structures, Binary Search Tree and Vector, had worse or equal performance in these areas.
After chosing a data structure I wrote pseudocode considering the requirements in place. The pseudicode acted as a roughdraft for the actual code, outlining how the program would work. After doing this I analysed the performance using Big-O notation to make sure none of the core functionality was inefficient with memory or runtimes.
## How did you overcome any roadblocks you encountered while going through the activities or project?
First I would do some testing to understand the problem and what might be causing it. Then I would try any alternate solutions I could think of to fix the issue. If this did not work I would do research on the problem to get a better idea of what I should do, then created a solution from there. 
## How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
Utilizing pseudocode allows for examination of the program, or parts of it, in an easy to read format. Using this the program can be designed and anylized before commiting to any code, which can result in better, more thought out, code structures.
