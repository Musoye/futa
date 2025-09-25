#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

struct QA_Node
{
    string id;
    string q;
    string answer;
    QA_Node *next;
};

struct Question
{
    string id;
    QA_Node *question;
};

struct Current
{
    string que;
    string ans;
};

class GameSetup
{
private:
    const string CATEGORY_FILES[6] = {
        "geography.csv",
        "history.csv",
        "science.csv",
        "movie.csv",
        "sport.csv",
        "computer.csv"};

    const string CATEGORY_NAMES[6] = {
        "Geography", "History", "Science", "Movie", "Sport", "Computer Engineering"};

    Question categories[6];
    int lives;
    int maxScore;
    int score;

    string trim(const string &s)
    {
        size_t start = s.find_first_not_of(" \t\n\r");
        size_t end = s.find_last_not_of(" \t\n\r");
        if (start == string::npos)
            return "";
        return s.substr(start, end - start + 1);
    }

    string normalize(const string &s)
    {
        string t = trim(s);
        transform(t.begin(), t.end(), t.begin(),
                  [](unsigned char c)
                  { return (char)tolower(c); });
        return t;
    }

    QA_Node *readQuestionsFromCSV(int categoryID)
    {
        if (categoryID < 0 || categoryID >= 6)
            return nullptr;

        string filename = CATEGORY_FILES[categoryID];
        ifstream file(filename);
        if (!file.is_open())
        {
            cerr << "Could not open file: " << filename << endl;
            return nullptr;
        }

        string line;
        // Removing the header of the csv
        if (getline(file, line))
        {
            string lower = line;
            transform(lower.begin(), lower.end(), lower.begin(),
                      [](unsigned char c)
                      { return (char)tolower(c); });
            if (lower.find("id") != string::npos ||
                lower.find("question") != string::npos ||
                lower.find("answer") != string::npos)
            {
            }
            else
            {
                file.seekg(0);
            }
        }

        QA_Node *head = nullptr;
        QA_Node *tail = nullptr;

        while (getline(file, line))
        {
            if (line.empty())
                continue;
            stringstream ss(line);
            string id, q, a;
            getline(ss, id, ',');
            getline(ss, q, ',');
            getline(ss, a);

            QA_Node *node = new QA_Node;
            node->id = id;
            node->q = q;
            node->answer = a;
            node->next = nullptr;

            if (!head)
                head = node;
            else
                tail->next = node;
            tail = node;
        }
        file.close();
        return head;
    }

    void freeAll()
    {
        for (int i = 0; i < 6; i++)
        {
            QA_Node *head = categories[i].question;
            while (head)
            {
                QA_Node *tmp = head;
                head = head->next;
                delete tmp;
            }
            categories[i].question = nullptr;
        }
    }

    void reload()
    {
        freeAll();
        categories[0] = {"geo", readQuestionsFromCSV(0)};
        categories[1] = {"hist", readQuestionsFromCSV(1)};
        categories[2] = {"sci", readQuestionsFromCSV(2)};
        categories[3] = {"movie", readQuestionsFromCSV(3)};
        categories[4] = {"sport", readQuestionsFromCSV(4)};
        categories[5] = {"computer", readQuestionsFromCSV(5)};
    }

    // Get a random question from a category lit and remove it
    Current *getRandomQuestion(QA_Node *&head)
    {
        if (!head)
            return nullptr;

        // 1. Count nodes
        int count = 0;
        for (QA_Node *p = head; p; p = p->next)
            count++;

        // 2. Pick random index
        int idx = rand() % count;

        // 3. Remove node at idx
        QA_Node *prev = nullptr;
        QA_Node *cur = head;
        for (int i = 0; i < idx; i++)
        {
            prev = cur;
            cur = cur->next;
        }

        if (prev)
            prev->next = cur->next; // unlinking node
        else
            head = cur->next; // removing first node

        Current *picked = new Current{cur->q, cur->answer};
        delete cur;
        return picked;
    }

public:
    GameSetup(int lives_ = 3, int maxScore_ = 10)
        : lives(lives_), maxScore(maxScore_), score(0)
    {
        for (int i = 0; i < 6; ++i)
        {
            categories[i].question = nullptr;
            categories[i].id = "";
        }
        srand((unsigned)time(NULL));
        reload();
    }

    ~GameSetup()
    {
        freeAll();
    }

    Current *rollDice(int &catIndexOut)
    {
        catIndexOut = rand() % 6;
        QA_Node *&head = categories[catIndexOut].question;
        if (!head)
            return nullptr;
        return getRandomQuestion(head);
    }

    bool checkAnswer(const string &userAns, const string &correctAns)
    {
        return normalize(userAns) == normalize(correctAns);
    }

    void addQuestion()
    {
        cout << "Select category:\n";
        cout << "0: Geography, 1: History, 2: Science, 3: Movie, 4: Sports, 5: Computer Engineering\n";
        int cat;
        if (!(cin >> cat))
        {
            cin.clear();
            cout << "Invalid input.\n";
            return;
        }
        cin.ignore();
        if (cat < 0 || cat >= 6)
        {
            cout << "Invalid category.\n";
            return;
        }

        string id, q, a;
        cout << "Enter ID: ";
        getline(cin, id);
        cout << "Enter Question: ";
        getline(cin, q);
        cout << "Enter Answer: ";
        getline(cin, a);

        ofstream file(CATEGORY_FILES[cat], ios::app);
        if (!file.is_open())
        {
            cerr << "Could not open file to append.\n";
            return;
        }
        file << id << "," << q << "," << a << "\n";
        file.close();

        cout << "Question added!\n";
        reload();
    }

    void startGame()
    {
        cout << "Welcome to Quiz Application!\n";
        cout << "1. Play Quiz\n";
        cout << "2. Add Question\n";
        cout << "Enter choice: ";
        int choice;
        if (!(cin >> choice))
        {
            cout << "Invalid input. Exiting.\n";
            return;
        }
        cin.ignore();

        if (choice == 2)
        {
            addQuestion();
            return;
        }

        lives = 3;
        score = 0;
        string ans;

        while (lives > 0 && score < maxScore)
        {
            cout << "\nType 'roll' to roll the dice: ";
            string rollInput;
            if (!getline(cin, rollInput))
                break;

            int catIndex;
            Current *randomQ = rollDice(catIndex);

            if (randomQ)
            {
                cout << "Dice rolled: Category " << (catIndex + 1)
                     << " (" << CATEGORY_NAMES[catIndex] << ")\n";
                cout << "Question: " << randomQ->que << endl;
                cout << "Your Answer: ";
                getline(cin, ans);

                if (checkAnswer(ans, randomQ->ans))
                {
                    score++;
                    cout << "Correct! Score: " << score << endl;
                }
                else
                {
                    lives--;
                    cout << "Wrong! The correct answer is: " << randomQ->ans << endl;
                    cout << "Lives left: " << lives << endl;
                }
                delete randomQ;
            }
            else
            {
                continue;
            }
        }
        cout << "Game over! Final score: " << score << endl;
        reload();
    }
};

int main()
{
    GameSetup game;
    game.startGame();
    return 0;
}
