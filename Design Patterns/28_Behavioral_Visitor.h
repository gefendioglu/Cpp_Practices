#pragma once

// Observer Design Pattern 
// ----------------------------------------------
// ----------------------------------------------

#ifdef BEHAVIORAL_VISITOR

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<list> 

/* Visitor Classes */
// ----------------------------------------------
class DocumentVisitor {
public:
    virtual void visit(class Markdown*) = 0;
    virtual void visit(class HTML*) = 0;
};

class DocumentPrinter : public DocumentVisitor {
public:
    void visit(Markdown* md) override;
    void visit(HTML* hd) override;
};

// ----------------------------------------------

class Document {
public:
    virtual void add_to_list(const std::string& line) = 0;
    virtual void visit(DocumentVisitor*) = 0; 
};

class Markdown : public Document {
public:
    void add_to_list(const std::string& line) override { 
        m_content.push_back(line); 
    }
    void visit(DocumentVisitor* dv) override {
        dv->visit(this); 
    }
    std::string m_start = "* ";
    std::list<std::string> m_content;
};

class HTML : public Document {
public:
    void add_to_list(const std::string& line) override {
        m_content.push_back(line); 
    }
    void visit(DocumentVisitor* dv) override {
        dv->visit(this);
    }
    std::string m_start = "<li>";
    std::string m_end = "</li>";
    std::list<std::string> m_content;
};

// ----------------------------------------------
void DocumentPrinter::visit(Markdown* md) {
    for (auto&& item : md->m_content)
        std::cout << md->m_start << item << "\n";
}

void DocumentPrinter::visit(HTML* hd) {
    std::cout << "<ul>" << "\n";
    for (auto&& item : hd->m_content)
        std::cout << "\t" << hd->m_start << item << hd->m_end << "\n";
    std::cout << "</ul>" << "\n";
}

// ----------------------------------------------

int main() {

    // Derived --> Base (upcasting)
    Document* d = new HTML;
    d->add_to_list("This is line");
    d->visit(new DocumentPrinter);

    return EXIT_SUCCESS;
    /*
        <ul>
            <li>This is line</li>
        <ul>
    */
}

#endif // BEHAVIORAL_VISITOR


#ifdef BEHAVIORAL_VISITOR_I
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<list> 
#include<variant> 

class Document {
public:
    virtual void add_to_list(const std::string& line) = 0;
};

class Markdown : public Document {
public:
    void add_to_list(const std::string& line) override {
        m_content.push_back(line);
    }
    
    std::string m_start = "* ";
    std::list<std::string> m_content;
};

class HTML : public Document {
public:
    void add_to_list(const std::string& line) override {
        m_content.push_back(line);
    }
    
    std::string m_start = "<li>";
    std::string m_end = "</li>";
    std::list<std::string> m_content;
};


/*  Visitor  */
struct DocumentPrinter {
    void operator()(Markdown& md) {
        for (auto&& item : md.m_content)
            std::cout << md.m_start << item << "\n";
    }
    void operator()(HTML& hd) {
        std::cout << "<ul>" << "\n";
        for (auto&& item : hd.m_content)
            std::cout << "\t" << hd.m_start << item << hd.m_end << "\n";
        std::cout << "</ul>" << "\n";
    }
};

using document = std::variant<Markdown, HTML>;

int main() {
    HTML hd;
    hd.add_to_list("This is line");
    document d = hd;
    DocumentPrinter dp;
    return EXIT_SUCCESS;
}

#endif // BEHAVIORAL_VISITOR
