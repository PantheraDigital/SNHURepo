#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

//file reading
#include <fstream> //file handling 
#include <sstream> //string stream

using namespace std;

const unsigned int DEFAULT_SIZE = 179;


//============================================================================
// Course struct definition
//============================================================================

struct Course {
    string courseNumber;
    string name;
    vector<string> prerequisites;

    Course(){}
    Course(string number, string name) 
    {
        courseNumber = number;
        this->name = name;
    }
    Course(string number, string name, vector<string> prerequisites)
        :Course(number, name)
    {
        this->prerequisites = prerequisites;
    }

    string GetTitle()
    {
        return courseNumber + ", " + name;
    }
};

/**
 * Allows for easier output of formatted Course data
 */
ostream& operator<<(ostream& os, const Course& course)
{
    os << course.courseNumber << ", " << course.name << endl;
    if (!course.prerequisites.empty())
    {
        os << "Prerequisites: ";
        for (int i = 0; i < course.prerequisites.size(); ++i)
        {
            os << course.prerequisites[i];
            if (i != course.prerequisites.size() - 1)
            {
                os << ", ";
            }
        }
        os << endl;
    }
    return os;
}


//============================================================================
// Hash Table class definition
//============================================================================

/**
 * Define a class containing data members and methods to
 * implement a hash table with chaining.
 */
class HashTable {

private:
    // Define structures to hold data
    struct Node {
        Course course;
        unsigned int key;
        Node* next;

        Node() {
            key = UINT_MAX;
            next = nullptr;
        }

        Node(Course course) : Node() {
            this->course = course;
        }

        Node(Course course, unsigned int aKey) : Node(course) {
            key = aKey;
        }
    };

    vector<Node*> nodes;

    unsigned int tableSize = DEFAULT_SIZE;
    unsigned int currentSize = 0;

    unsigned int hash(string str);

    void deleteLinkedList(Node* head);

public:
    HashTable();
    HashTable(unsigned int size);
    virtual ~HashTable();
    void Insert(Course course);
    void PrintAll();
    void PrintOrdered();
    void Remove(string courseNumber);
    Course Search(string courseNumber);
    size_t Size();
};


HashTable::HashTable() {
    nodes = vector<Node*>(tableSize);
}

HashTable::HashTable(unsigned int size) {
    tableSize = size;
    nodes = vector<Node*>(tableSize);
}

/**
 * Destructor
 */
HashTable::~HashTable() {
    for (size_t i = 0; i < nodes.size(); i++)
    {
        deleteLinkedList(nodes[i]);
    }
}

/**
 * Recursive linked list deleter
 */
void HashTable::deleteLinkedList(Node* head)
{
    if (head == nullptr) { return; }
    deleteLinkedList(head->next);
    delete head;
}

/**
 * Calculate the hash value of a given key.
 *
 * @param key The key to hash
 * @return The calculated hash
 */
unsigned int HashTable::hash(string str) {
    int key = 0;

    if (str.empty())
        return 0;

    // an atempt to make a better has function 
    for (int i = 0; i < str.size(); ++i)
    {
        key += int(str[i]) * i;
    }

    return key % tableSize;
}

/**
 * Insert a course
 *
 * @param course The course to insert
 */
void HashTable::Insert(Course course) {
    unsigned int key = hash(course.courseNumber);
    if (nodes[key] == nullptr)
    {
        nodes[key] = new Node(course, key);
    }
    else
    {
        // place the new node at the head of the bucket
        //  and old head node after new head
        Node* newNode = new Node(course, key);
        newNode->next = nodes[key];
        nodes[key] = newNode;
    }
    currentSize++;
}

/**
 * Print all courses
 */
void HashTable::PrintAll() {
    if (currentSize == 0)
    {
        cout << "Empty" << endl;
        return;
    }
    for (size_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i] != nullptr)
        {
            cout << nodes[i]->course << endl;

            Node* next = nodes[i]->next;
            while (next != nullptr)
            {
                cout << next->course << endl;
                next = next->next;
            }
        }
    }
}

/**
 * Print all courses in alphanumeric order
 */
void HashTable::PrintOrdered()
{
    if (currentSize == 0)
    {
        cout << "Empty" << endl;
        return;
    }

    // place course titles in a vector
    int courseDataIndex = 0;
    vector<string> courseData = vector<string>(currentSize);
    for (size_t i = 0; i < nodes.size(); i++)
    {
        if (nodes[i] != nullptr)
        {
            courseData[courseDataIndex] = nodes[i]->course.GetTitle();
            ++courseDataIndex;
            
            Node* next = nodes[i]->next;
            while (next != nullptr)
            {
                courseData[courseDataIndex] = next->course.GetTitle() + " bucket";
                ++courseDataIndex;
                ++i;
                next = next->next;
            }
        }
    }

    // sort and print vector
    sort(courseData.begin(), courseData.end());
    for (string courseNumber : courseData)
    {
        cout << courseNumber << endl;
    }
}

/**
 * Remove a course
 *
 * @param courseNumber The course to search for
 */
void HashTable::Remove(string courseNumber) {
    unsigned int key = hash(courseNumber);

    if (currentSize == 0 || nodes[key] == nullptr)
        return;

    if (nodes[key]->course.courseNumber == courseNumber)
    {
        // remove head
        if (nodes[key]->next != nullptr)
        {
            // head has a next node
            Node* temp = nodes[key]->next;
            delete nodes[key];
            nodes[key] = temp;
        }
        else
        {
            delete nodes[key];
        }
        currentSize--;
    }
    else if(nodes[key]->next != nullptr) // search linked list for match
    {
        Node* cur = nodes[key];
        while (cur->next != nullptr)
        {
            if (cur->next->course.courseNumber == courseNumber)
            {
                Node* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;
                currentSize--;
                break;
            }
            cur = cur->next;
        }
    }
}

/**
 * Search for the specified courseNumber
 *
 * @param courseNumber The course to search for
 */
Course HashTable::Search(string courseNumber) {
    Course course;
    unsigned int key = hash(courseNumber);

    if (currentSize == 0 || nodes[key] == nullptr)
        return course;

    if (nodes[key]->course.courseNumber == courseNumber)
    {
        return nodes[key]->course;
    }
    else if(nodes[key]->next != nullptr)
    {
        Node* temp = nodes[key]->next;
        while (temp != nullptr)
        {
            if (temp->course.courseNumber == courseNumber)
            {
                return temp->course;
            }
            temp = temp->next;
        }
    }

    return course;
}

size_t HashTable::Size()
{
    return currentSize;
}


//============================================================================
// Helper Functions
//============================================================================

/**
 * Print menu 
 */
void DisplayMenu() 
{
    cout << "Menu:" << endl;
    cout << "  1. Load Courses" << endl;
    cout << "  2. Display Courses" << endl;
    cout << "  3. Display Course Info" << endl;
    cout << "  9. Exit" << endl;
    cout << "Enter choice: ";
}

/**
 * Returns string as int if string is all numbers. Otherwise returns INT_MAX.
 */
int IsInt(const string& s)
{
    for (char c : s)
    {
        if (!isdigit(c))
        {
            return INT_MAX;
        }
    }
    return atoi(s.c_str());
}

/**
 * Reads a CSV file placing each value in a vector
 * Lines from the file are seperated by an element ";" in the vector
 * Each value from the file is its own element in the vector
 * 
 * @param name The file name or path to read from
 * @return A vector of strings containing the values from the file. Seperates lines with an ";" element. Returns an empty vector if file does not open.
 */
vector<string> LoadFile(const string& name)
{
    ifstream f(name);
    vector<string> subsrtings;

    if (!f.is_open()) {
        cout << "Error opening the file" << endl;
        return subsrtings;
    }

    string s;
    while (getline(f, s)) // place line from file into string
    {
        // read each substring seperated by a ','
        stringstream ss(s);
        while (ss.good())
        {
            string substr;
            getline(ss, substr, ',');
            if (substr != "") // commas with no text after result in an empty string
                subsrtings.push_back(substr);
        }
        subsrtings.push_back(";"); // new line of file
    }

    f.close();
    return subsrtings;
}


int main() {
    HashTable hash;
    string choice = "";

    while (choice != "9")
    {
        DisplayMenu();
        cin >> choice;
        cin.ignore(256, '\n'); // clear any extra input that would flow into getline or cause double input with cin
        cout << endl;

        // verify input is a number and is 1-3 or 9
        int choiceToInt = IsInt(choice);
        if (choiceToInt == INT_MAX || (choiceToInt != INT_MAX && !((choiceToInt <= 3 && choiceToInt >= 1) || choiceToInt == 9) ) )
        {
            cout << "Unrecognized Input: " << choice << endl << endl;
            continue;
        }

        switch (choiceToInt)
        {
        case 1: // Load Courses
        {
            // gather file name or path
            cout << "Input File Name or File Path: ";
            getline(cin, choice);

            // load courses from file
            vector<string> data = LoadFile(choice);
            if (data.empty())
                break;

            hash = HashTable(data.size());
            Course course;

            for (string element : data)
            {
                if (element == ";")
                {
                    //end of course data
                    // verify at least number and name are set
                    // add to hashtable
                    if (course.courseNumber != "" && course.name != "")
                    {
                        hash.Insert(course);
                        course = Course();
                    }
                }
                else if (course.courseNumber == "")
                {
                    course.courseNumber = element;
                }
                else if (course.name == "")
                {
                    course.name = element;
                }
                else
                {
                    // verify prereq is already added as a course
                    if (hash.Search(element).courseNumber != "")
                        course.prerequisites.push_back(element);
                }
            }
            cout << "Courses Loaded." << endl;
            break;
        }
        case 2: // Display Courses
            // print sorted courses
            hash.PrintOrdered();
            break;
        case 3: // Display Course Info
        {
            cout << "Input Course Number: ";
            cin >> choice;
            cin.ignore(256, '\n'); // prevent double input when user input contains a space
            transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

            Course course = hash.Search(choice);
            if (course.courseNumber != "")
            {
                cout << course;
            }
            else
            {
                cout << choice << " not found." << endl;
            }

            break;
        }
        }
        cout << endl;
    }
}