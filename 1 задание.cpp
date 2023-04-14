#include <iostream>
#include <vector>
#include <string>

enum class type {
    Art, Tech, None
};

class book {
public:
    book(const std::string& auth, const std::string& nam, type gen) : author(auth), m_name(nam), type(gen) {
    }
    type get_genre()const {
        return type;
    }
private:
    const std::string m_name, author;
    const type type;
};

class library {
public:

    void AddBook(const std::string& auth, const std::string& name, const type& gen) {
        if (!auth.empty() && !name.empty()) {
            book_collection.emplace_back(new book(auth, name, gen));
        }
    }
    ~library() {
        for (auto book : book_collection) {
            delete book;
        }
    }
    void Count() {
        int art = 0,
            tech = 0;
        for (auto book : book_collection) {
            switch (book->get_genre())
            {
            case type::Art:
                ++art;
                break;
            case type::Tech:
                ++tech;
                break;
            }
        }
        std::cout << "with switch" << std::endl;
        std::cout << "Художественных книг: " << art << std::endl;
        std::cout << "Технических книг: " << tech << std::endl;
    }
    void withoutSwCount() {
        int art = 0,
            tech = 0;
        for (auto book : book_collection) {

            if (book->get_genre() == type::Art) {
                ++art;
            }
            else if ((book->get_genre() == type::Tech)) {
                ++tech;
            }
        }
        std::cout << "witout switch" << std::endl;
        std::cout << "Художественных книг: " << art << std::endl;
        std::cout << "Технических книг: " << tech << std::endl;
    }
private:
    std::vector<book*> book_collection;
};


int main()
{
    setlocale(LC_ALL, "Ru");
    library lib;
    lib.AddBook("Человек", "Капитанская дочка", type::Art);
    lib.AddBook("Reaper", "Мёртвые души", type::Tech);
    lib.AddBook("ReaperSon", "Мёртвые души 2", type::Tech);
    lib.Count();
    lib.withoutSwCount();
    return 0;
}