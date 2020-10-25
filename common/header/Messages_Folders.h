//
// Created by KK on 2020/10/17.
//

#ifndef C___PRIMER_EXERCISE_MESSAGES_FOLDERS_H
#define C___PRIMER_EXERCISE_MESSAGES_FOLDERS_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <memory>
#include <set>


// Messages和Folders互为友元类
// 在Messages中save或者remove，对应的Folder中的msg应该同样更改；
// 在Folder中addMsg或者rmMsg,对应的Message中的folder应该同样更改；
// TODO:类结构优化


// 前置声明
class Folders;

class Messages {

    friend class Folders;

    friend void swap(Messages &lm, Messages &rm);

public:
    Messages() = default;

    explicit Messages(std::string msg_string) : msg_contents(std::move(msg_string)) {}

    // 拷贝一个Message的全部内容后对应的Folder内需要添加一条当前消息
    Messages(const Messages &m) : msg_contents(m.msg_contents) { addToFolders(); }

    Messages &operator=(const Messages &m);

    ~Messages() { rmFromFolders(); }

    void save(Folders *f);

    void remove(Folders *f);

    void print();

    void change(const std::string &new_msg_contents);

    void addToFolders(Folders *f);

    void rmFromFolders(Folders *f);

private:
    std::set<Folders *> msg_folders;
    std::string msg_contents;

    void addToFolders();

    void rmFromFolders();
};

class Folders {

    friend void swap(Folders &lf, Folders &rf);

    friend class Messages;

public:
    Folders() = default;

    Folders(const Folders &f) : folders_msgs(f.folders_msgs) { addToMessages(); }

    Folders &operator=(const Folders &f);

    ~Folders() { rmFromMessages(); }

    void addMsg(Messages *m);

    void rmMsg(Messages *m);

    void print();

private:
    std::set<Messages *> folders_msgs;

    void addToMessages();

    void rmFromMessages();
};

// Messages Public;
inline Messages &Messages::operator=(const Messages &m) {
    rmFromFolders();
    msg_contents = m.msg_contents;
    msg_folders = m.msg_folders;
    addToFolders();
    return *this;
}

inline void Messages::save(Folders *f) {
    msg_folders.insert(f);
    f->folders_msgs.insert(this);
}

inline void Messages::remove(Folders *f) {
    msg_folders.erase(f);
    f->folders_msgs.erase(this);
}

void Messages::print() {
    std::cout << "消息内容:" << msg_contents << std::endl;
    std::cout << "目录地址:";
    for (const auto &cf: msg_folders) {
        std::cout << cf << "  ";
    }
    std::cout << std::endl;
}

inline void Messages::change(const std::string &new_msg_contents) { msg_contents = new_msg_contents; }

inline void Messages::addToFolders(Folders *f) { f->folders_msgs.insert(this); }

inline void Messages::rmFromFolders(Folders *f) { f->folders_msgs.erase(this); }

// Messages Private;
void Messages::addToFolders() {
    for (const auto &cf: msg_folders) { addToFolders(cf); }
}

void Messages::rmFromFolders() {
    for (const auto &cf: msg_folders) { rmFromFolders(cf); }
}


void swap(Messages &lm, Messages &rm) {
    using std::swap;
    // 先移除在Folder中所有lm和rm
    lm.rmFromFolders();
    rm.rmFromFolders();
    // swap内容
    swap(lm.msg_contents, rm.msg_contents);
    swap(lm.msg_folders, rm.msg_folders);
    // 在Folder中添加交换后的lm和rm
    lm.addToFolders();
    rm.addToFolders();
}


// Folders Public;
inline Folders &Folders::operator=(const Folders &f) {
    rmFromMessages();
    folders_msgs = f.folders_msgs;
    addToMessages();
    return *this;
}

inline void Folders::addMsg(Messages *m) {
    m->msg_folders.insert(this);
    folders_msgs.insert(m);
}

inline void Folders::rmMsg(Messages *m) {
    m->msg_folders.erase(this);
    folders_msgs.erase(m);
}

void Folders::print() {
    std::cout << "目录地址:" << this << std::endl;
    std::cout << "目录内容:";
    for (const auto &cm : folders_msgs) {
        std::cout << cm->msg_contents << "  ";
    }
    std::cout << std::endl;
}

// Folders Private;
void Folders::addToMessages() {
    for (const auto &cm : folders_msgs) {
        cm->msg_folders.insert(this);
    }
}

void Folders::rmFromMessages() {
    for (const auto &cm : folders_msgs) {
        cm->msg_folders.erase(this);
    }
}

void swap(Folders &lf, Folders &rf) {
    using std::swap;
    // 先在所有Message中移除lf和rf
    lf.rmFromMessages();
    rf.rmFromMessages();
    // swap内容
    swap(lf.folders_msgs, rf.folders_msgs);
    // 在所有Messages中添加新的lf和rf
    lf.addToMessages();
    rf.addToMessages();
}

#endif //C___PRIMER_EXERCISE_MESSAGES_FOLDERS_H
