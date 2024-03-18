#include <iostream>
#include <string>

using namespace std;

struct Character {
    string name;
    int level;
    double winRate;
    string comment;
    Character* next;
};

void FirstAdd(Character*& head, const string& name, int level, double winRate) {
    Character* newCharacter = new Character;
    newCharacter->name = name;
    newCharacter->level = level;
    newCharacter->winRate = winRate;
    newCharacter->next = head;
    head = newCharacter;
}

void AddEnd(Character*& head, const string& name, int level, double winRate) {
    Character* newCharacter = new Character;
    newCharacter->name = name;
    newCharacter->level = level;
    newCharacter->winRate = winRate;
    newCharacter->next = nullptr;

    if (head == nullptr) {
        head = newCharacter;
        return;
    }

    Character* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newCharacter;
}

void AddAfter(Character* head, const string& targetName, const string& name, int level, double winRate) {
    Character* temp = head;
    while (temp != nullptr && temp->name != targetName) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Character* newCharacter = new Character;
        newCharacter->name = name;
        newCharacter->level = level;
        newCharacter->winRate = winRate;
        newCharacter->next = temp->next;
        temp->next = newCharacter;
    }
    else {
        cout << "Target character '" << targetName << "' not found!" << endl;
    }
}

void AddBefore(Character*& head, const string& targetName, const string& name, int level, double winRate) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->name == targetName) {
        FirstAdd(head, name, level, winRate);
        return;
    }

    Character* prev = nullptr;
    Character* temp = head;
    while (temp != nullptr && temp->name != targetName) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != nullptr) {
        Character* newCharacter = new Character;
        newCharacter->name = name;
        newCharacter->level = level;
        newCharacter->winRate = winRate;
        newCharacter->next = temp;
        prev->next = newCharacter;
    }
    else {
        cout << "Target character '" << targetName << "' not found!" << endl;
    }
}

void kick_dauna(Character*& head, const string& name) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    Character* temp = head;
    Character* prev = nullptr;

    while (temp != nullptr && temp->name != name) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Character '" << name << "' not found!" << endl;
        return;
    }

    if (prev == nullptr) {
        head = head->next;
    }
    else {
        prev->next = temp->next;
    }

    delete temp;
}


void printList(Character* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }

    cout << "Dota 2 Characters:" << endl;
    while (head != nullptr) {
        cout << "Name: " << head->name << ", Level: " << head->level << ", Win Rate: " << head->winRate << endl;
        head = head->next;
    }
}

int main() {
    Character* head = nullptr;
    FirstAdd(head, "Invoker", 25, 0.65);
    AddEnd(head, "Sven", 30, 0.75);
    AddAfter(head, "Invoker", "Zeus", 20, 0.60);
    AddBefore(head, "Sven", "Drow Ranger", 28, 0.70);
    kick_dauna(head, "Invoker");

    string heroName = "Invoker";

    printList(head);

    cout << "Player on " << heroName << " is stupid" << endl;

    return 0;
}
