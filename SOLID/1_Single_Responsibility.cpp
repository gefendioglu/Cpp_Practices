#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string>
#include<vector>

class Journal {
public:
    explicit Journal(const std::string& title) : m_title{ title } {}
    void add_entries(const std::string& entry) {
        static uint32_t count = 1;
        m_entries.push_back(std::to_string(count++) + ": " + entry);
    }
    auto get_entries() const { return m_entries; }

    //void save(const std::string& filename) {
    //    std::ofstream ofs(filename);
    //    for (auto& s : m_entries) 
    //        ofs << s << "\n";
    //}

private: 
    std::string m_title;
    std::vector<std::string>  m_entries;
};

 //Instead of using a "save" function in Journal class :
 //As your SavingManager grows, you have all the saving related code will be at one place.
 //You can also templatize it to accept more domain objects.
struct SavingManager {
    static void save(const Journal& j, const std::string& filename) {
        std::ofstream ofs(filename);
        for (auto& s : j.get_entries())
            ofs << s << "\n";
    }
};

int  main() {
    Journal journal{ "Dear XYZ" };
    journal.add_entries("I ate a bug");
    journal.add_entries("I cried today");
    SavingManager::save(journal, "diary.txt");

    return EXIT_SUCCESS;
}
