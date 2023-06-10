// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;


class CommunicationCenter {
public:
    virtual void Cheer() = 0;
    virtual void Goodbye() = 0;
};

class EnCommunicationCenter : public CommunicationCenter {
public:
    void Cheer() override {
        std::cout << "Cheer for your team!" << std::endl;
    }
    void Goodbye() override {
        std::cout << "Goodbye and see you next time!" << std::endl;
    }
};

class FrAdapter : public CommunicationCenter {
private:
    EnCommunicationCenter* en_center;
public:
    FrAdapter(EnCommunicationCenter* en_center) : en_center(en_center) {}
    void Cheer() override {
        std::cout << "Bravo pour votre équipe!" << std::endl;
        en_center->Cheer();
    }
    void Goodbye() override {
        std::cout << "Au revoir et nouvelles rencontres!" << std::endl;
        en_center->Goodbye();
    }
};

class FrCommunicationCenter {
private:
    FrAdapter* adapter;
public:
    FrCommunicationCenter(FrAdapter* adapter) : adapter(adapter) {}
    void communicate() {
        adapter->Cheer();
        adapter->Goodbye();
    }
};



int main() {





    // создаем объект EnCommunicationCenter
    EnCommunicationCenter* en_center = new EnCommunicationCenter();

    // создаем объект FrAdapter на основе EnCommunicationCenter
    FrAdapter* adapter = new FrAdapter(en_center);

    // создаем объект FrCommunicationCenter на основе FrAdapter
    FrCommunicationCenter* fr_center = new FrCommunicationCenter(adapter);

    // общаемся с Центром коммуникации на французском языке через адаптер
    fr_center->communicate();



    return 0;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
