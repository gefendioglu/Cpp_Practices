#pragma once

/* Before applying Interface Segregation Principles */
// ------------------------------------------------
/*
class Document;
class IMachine {
public:
    virtual void print(Document& doc) = 0;
    virtual void fax(Document& doc) = 0;
    virtual void scan(Document& doc) = 0;
};

class MultiFunctionPrinter : IMachine {  // OK
public:
    void print(Document& doc) override { }
    void fax(Document& doc) override { }
    void scan(Document& doc) override { }
};

class Scanner : IMachine {  // Not OK
public:
    void print(Document& doc) override { }
    void fax(Document& doc) override { }
    void scan(Document& doc) override {
        // Do scanning ...
    }
};
*/

/* After applying Interface Segregation Principles */
// ------------------------------------------------

#ifdef INTERFACE_SEGREGATION_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

class Document {
public:
    int mx;
};

// Interfaces
class IPrinter {
public:
    virtual void print(Document& doc) = 0;
};

class IScanner {
public:
    virtual void scan(Document& doc) = 0;
};

class Printer : public IPrinter {
public:
    void print(Document& doc) override;
};

class Scanner : public IScanner {
public:
    void scan(Document& doc) override;
};

class IMachine : public IPrinter, public IScanner { };

class Machine : public IMachine {
public:
    Machine(Printer& p, Scanner& s) : m_printer{ p }, m_scanner{ s } { }

    void print(Document& doc) override {
        m_printer.print(doc);
    }

    void scan(Document& doc) override {
        m_scanner.scan(doc);
    }

private:
    IPrinter& m_printer;
    IScanner& m_scanner;
};

int main() {

    Printer printer;
    Scanner scanner;
    Document doc;

    Machine machine(printer, scanner); 
    machine.print(doc);
    machine.scan(doc);

    return EXIT_SUCCESS;
}

#endif // INTERFACE_SEGREGATION_I