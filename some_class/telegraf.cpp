//https://contest.yandex.ru/contest/60944/problems/B/
#include <iostream>

using namespace std;

void SendBK(const string &id, const string &message) {
    cout << "Send '" << message << "' to BK user " << id << endl;
}

void SendTelegraph(const string &login, const string &message) {
    cout << "Send '" << message << "' to Telegraph user " << login << endl;
}

class NotifierBase {
public:
    virtual void notify(const string &message) = 0;
};

class BKNotifier : public NotifierBase {
private:
    string id;

public:
    BKNotifier(const string &user_id) {
        this->id = user_id;
    }

    void notify(const string &message) {
        SendBK(id, message);
    }
};


class TelegraphNotifier : public NotifierBase {
private:
    string login;

public:
    TelegraphNotifier(const string &user_login) {
        this->login = user_login;
    }

    void notify(const string &message) {
        SendTelegraph(login, message);
    }
};
