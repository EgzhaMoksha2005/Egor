#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

class Men {
public:
    string surname;
    string name;
    string middlename;
    string date;
    

    Men() {}

    Men(string sn, string n, string mn, string d) {
        surname = sn;
        name = n;
        middlename = mn;
        date = d;
    }

    void display() {
        cout << "Автор: " << author << "\n";
        cout << "Название: " << title << "\n";
        cout << "Издательство: " << publisher << "\n";
        cout << "Год: " << year << "\n";
        cout << "Количество страниц: " << pages << "\n";
    }
};
class Student : public Men {
public:
    string group;
    float  avaragemark;
};

class teacher : public Men {
public:
    string subject;
    float  seniority;
};

void addBook(vector<Men>& men) {
    string surname, title, publisher;
    int year, pages;

    cout << "\nВведите автора: ";
    cin.ignore();
    getline(cin, );

    cout << "Введите название: ";
    getline(cin, title);

    cout << "Введите издательство: ";
    getline(cin, publisher);

    cout << "Введите год: ";
    cin >> year;

    cout << "Введите количество страниц: ";
    cin >> pages;

    books.push_back(Book(author, title, publisher, year, pages));
}

void printAuthorBooks(vector<Book>& books, string targetAuthor) {
    cout << "\nКниги автора " << targetAuthor << ":\n";
    for (Book book : books) {
        if (book.author == targetAuthor) {
            book.display();
            cout << "\n";
        }
    }
}

void printPublisherBooks(vector<Book>& books, string targetPublisher) {
    cout << "\nКниги, изданные " << targetPublisher << ":\n";
    for (Book book : books) {
        if (book.publisher == targetPublisher) {
            book.display();
            cout << "\n";
        }
    }
}

void printBooksAfterYear(vector<Book>& books, int targetYear) {
    cout << "\nКниги, изданные после " << targetYear << ":\n";
    for (Book book : books) {
        if (book.year > targetYear) {
            book.display();
            cout << "\n";
        }
    }
}

void saveToFile(vector<Book>& books, string filename) {
    ofstream file(filename);

    if (!file) {
        cout << "Ошибка открытия файла.\n";
        return;
    }

    for (Book book : books) {
        file << "Имя автора: " << book.author << "\n";
        file << "Название книги: " << book.title << "\n";
        file << "Издательство: " << book.publisher << "\n";
        file << "Год издания: " << book.year << "\n";
        file << "Количество страниц: " << book.pages << "\n";
    }

    file.close();
    cout << "Данные сохранены в " << filename << ".\n";
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Book> books;
    int choice;
    string targetAuthor, targetPublisher, filename;
    int targetYear;

    do {
        cout << "1. Добавить книгу\n";
        cout << "2. Вывести книги автора\n";
        cout << "3. Вывести книги издательства\n";
        cout << "4. Вывести книги, изданные после заданного года\n";
        cout << "5. Сохранить в файл\n";
        cout << "6. Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addBook(books);
            break;
        case 2:
            cout << "Введите автора: ";
            cin.ignore();
            getline(cin, targetAuthor);
            printAuthorBooks(books, targetAuthor);
            break;
        case 3:
            cout << "Введите издательство: ";
            cin.ignore();
            getline(cin, targetPublisher);
            printPublisherBooks(books, targetPublisher);
            break;
        case 4:
            cout << "Введите год: ";
            cin >> targetYear;
            printBooksAfterYear(books, targetYear);
            break;
        case 5:
            cout << "\nВведите имя файла: ";
            cin.ignore();
            getline(cin, filename);
            saveToFile(books, filename);
            break;
        case 6:
            cout << "\nВыход...\n";
            break;
        default:
            cout << "\nНеверный выбор. Попробуйте снова.\n";
        }
    } while (choice != 6);
    return 0;
}