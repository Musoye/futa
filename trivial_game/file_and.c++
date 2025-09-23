#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;


struct QA_Node {
    string id;
    string q;
    string answer;
    QA_Node *next;
};


struct Question {
    string id;          // category id like "geo"
    QA_Node *question;
};

// category constants
const int CAT_GEOGRAPHY = 0;
const int CAT_HISTORY   = 1;
const int CAT_SCIENCE   = 2;
const int CAT_MOVIE     = 3;
const int CAT_SPORT     = 4;


const string CATEGORY_FILES[] = {
    "geography.csv",    // 0
    "history.csv",      // 1
    "science.csv",      // 2
    "movie.csv",        // 3
    "sports.csv"        // 4
};

// trim leading/trailing spaces
string trim(const string &s) {
    size_t start = s.find_first_not_of(" \t\n\r");
    size_t end   = s.find_last_not_of(" \t\n\r");
    return (start == string::npos) ? "" : s.substr(start, end - start + 1);
}

// lowercase + trim
string normalize(const string &s) {
    string t = trim(s);
    transform(t.begin(), t.end(), t.begin(),
              [](unsigned char c){ return std::tolower(c); });
    return t;
}

// read CSV into linked list
QA_Node* readQuestionsFromCSV(int categoryID) {
    if (categoryID < 0 || categoryID >= (int)(sizeof(CATEGORY_FILES)/sizeof(CATEGORY_FILES[0])))
        return nullptr;

    string filename = CATEGORY_FILES[categoryID];

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file: " << filename << endl;
        return nullptr;
    }

    string line;
    getline(file, line); // skip header
    QA_Node *head = nullptr, *tail = nullptr;

    while (getline(file, line)) {
        stringstream ss(line);
        string id, q, a;
        getline(ss, id, ',');
        getline(ss, q, ',');
        getline(ss, a);

        QA_Node *node = new QA_Node{id, q, a, nullptr};
        if (!head) head = node; else tail->next = node;
        tail = node;
    }
    file.close();
    return head;
}

// write linked list back to CSV
int writeQuestionsToCSV(int categoryID, QA_Node *head) {
    if (categoryID < 0 || categoryID >= (int)(sizeof(CATEGORY_FILES)/sizeof(CATEGORY_FILES[0])))
        return -1;

    string filename = CATEGORY_FILES[categoryID];

    ofstream file(filename);
    if (!file.is_open()) {
        cerr << "Could not open file for writing: " << filename << endl;
        return -1;
    }

    file << "id,question,answer\n";
    QA_Node *cur = head;
    while (cur) {
        file << cur->id << "," << cur->q << "," << cur->answer << "\n";
        cur = cur->next;
    }
    file.close();
    return 0;
}

struct Current {
    string que;
    string ans;
};

// get a random question from a linked list, remove it, return it
Current *getRandomQuestion(QA_Node *&head) {
    // count
    int count = 0;
    QA_Node *cur = head;
    while (cur) { count++; cur = cur->next; }
    if (count == 0) return nullptr;

    int index = rand() % count; // random 0..count-1

    // find the node at that index
    QA_Node *prev = nullptr;
    cur = head;
    for (int i = 0; i < index; i++) {
        prev = cur;
        cur = cur->next;
    }

    // remove node from list
    if (prev) prev->next = cur->next; else head = cur->next;

    // package question
    Current *new_que = new Current;
    new_que->que = cur->q;
    new_que->ans = cur->answer;

    delete cur;
    return new_que;
}

// pick a random category, then random question from it
Current *getRandomQuestionAllCategories(Question categories[], int numCats) {
    // pick random category first
    int catIndex = rand() % numCats; // 0..numCats-1
    QA_Node *&head = categories[catIndex].question;
    if (!head) return nullptr;

    return getRandomQuestion(head);
}

// class GameSetup {

// public:
//     GameSetup() {
int main() {
    srand((unsigned)time(nullptr));
    int LIVES = 3;
    int MAX_SCORE = 10;
    int SCORE = 0;
    string ans;

    cout << "Quiz Application\n";

    // initialize all categories
    Question categories[5] = {
        {"geo",   readQuestionsFromCSV(CAT_GEOGRAPHY)},
        {"hist",  readQuestionsFromCSV(CAT_HISTORY)},
        {"sci",   readQuestionsFromCSV(CAT_SCIENCE)},
        {"movie", readQuestionsFromCSV(CAT_MOVIE)},
        {"sport", readQuestionsFromCSV(CAT_SPORT)}
    };

    // Game loop
    while (LIVES > 0 && SCORE < MAX_SCORE) {
        Current *randomQ = getRandomQuestionAllCategories(categories, 5);
        if (randomQ) {
            cout << "Question: " << randomQ->que << endl;
            cout << "Your Answer: ";
            getline(cin, ans);

            if (normalize(ans) == normalize(randomQ->ans)) {
                SCORE++;
                cout << "Correct! Score: " << SCORE << endl;
            } else {
                LIVES--;
                cout << "Wrong! The correct answer is: " << randomQ->ans
                     << ". Lives left: " << LIVES << endl;
            }
            delete randomQ;
        } else {
            continue;
        }
    }

    cout << "Game over! Final score: " << SCORE << endl;

    // free memory
    for (int i = 0; i < 5; i++) {
        QA_Node *head = categories[i].question;
        while (head) {
            QA_Node *tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    return 0;
};