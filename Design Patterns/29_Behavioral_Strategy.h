#pragma once

// Dynamic Strategy - TO BE CONTROLLED - NOT COMPILED
// ----------------------------------------------
// ----------------------------------------------

#ifdef BEHAVIORAL_STRATEGY_EXAMPLE_I

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string> 
#include<vector> 

enum class Format { Markdown, Html };

// Base Class
class ListStrategy {
public:
    virtual ~ListStrategy() = default;
    virtual void add_list_item(std::ostringstream& oss, std::string& item) {};
    virtual void start(std::ostringstream& oss) {};
    virtual void end(std::ostringstream& oss) {};
};

// Derived Class
class MarkdownListStrategy : public ListStrategy {
public:
    void add_list_item(std::ostringstream& oss, std::string& item) override { 
		oss << " - " << item << "\n"; 
	}
};

// Derived Class
class HtmlListStrategy : public ListStrategy {
    void start(std::ostringstream& oss) override {
        oss << "<ul>" << "\n"; 
    }

    void end(std::ostringstream& oss) override {
        oss << "</ul>" << "\n";
    }

    void add_list_item(std::ostringstream& oss, std::string& item) override{
        oss << "\t<li>" << item << "</li>" << "\n";
    }
};

class TextProcessor {
public:
    
	void clear() {
        m_oss.str("");
        m_oss.clear();
    }

    void append_list(std::vector<std::string>& items) {
        
		m_list_strategy->start(m_oss);
        
		for (auto& item : items)
            m_list_strategy->add_list_item(m_oss, item);
       
		m_list_strategy->end(m_oss);
    }

    void set_output_format(Format& format) {
        switch (format) {
        case Format::Markdown: m_list_strategy = std::make_unique<MarkdownListStrategy>(); break;
        case Format::Html: m_list_strategy = std::make_unique<HtmlListStrategy>(); break;
        }
    }

    std::string str() { return m_oss.str(); }

private:
	std::ostringstream m_oss;
	std::unique_ptr<ListStrategy> m_list_strategy;
};

int main() {
	std::vector<std::string> text = { "foo", "bar", "baz" };
	Format mdFormat = Format::Markdown;
	Format htmlFormat = Format::Html;
	
	// markdown
    TextProcessor tp;
    tp.set_output_format(mdFormat);
    tp.append_list(text);
    std::cout << tp.str() << "\n";

	// dynamic type definition for markdown generation
	/*TextProcessor<MarkdownListStrategy> tp1;
	tp1.append_list({ "foo", "bar", "baz" });
	std::cout << tp1.str() << std::endl;*/

    // html
    tp.clear();
    tp.set_output_format(htmlFormat);
    tp.append_list(text);
    std::cout << tp.str() << "\n";

	// static type definition for html generation
	/*TextProcessor<HtmlListStrategy> tp2;
	tp2.append_list({ "foo", "bar", "baz" });
	std::cout << tp2.str() << std::endl;*/

	/* For static type definition template template<typename LS> to represent std::unique_ptr<ListStrategy> type */

    return EXIT_SUCCESS;
    
    /*
     - foo
     - bar
     - baz

    <ul>
        <li>foo</li>
        <li>bar</li>
        <li>baz</li>
    </ul>
    */
}

#endif // BEHAVIORAL_STRATEGY_EXAMPLE_I



// Strategy Pattern - GeeksForGeeks 
// ----------------------------------------------
// ----------------------------------------------

#ifdef BEHAVIORAL_STRATEGY_EXAMPLE_II

#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 

// Abstract as you must have a specific fighter 
class Fighter {
public:
	// Constructor
	Fighter(KickBehavior *kickBehavior,JumpBehavior *jumpBehavior){
		this->jumpBehavior = jumpBehavior;
		this->kickBehavior = kickBehavior;
	}

	void punch(){
		std::cout << "Default Punch" << "\n";
	}

	void kick(){
		// delegate to kick behavior 
		kickBehavior->kick();
	}

	void jump(){
		// delegate to jump behavior 
		jumpBehavior->jump();
	}

	void roll()	{
		std::cout << "Default Roll" << "\n";
	}

	void setKickBehavior(KickBehavior *kickBehavior)
	{
		this->kickBehavior = kickBehavior;
	}

	void setJumpBehavior(JumpBehavior *jumpBehavior)
	{
		this->jumpBehavior = jumpBehavior;
	}

	virtual void display()=0;

private:
	KickBehavior *kickBehavior;
	JumpBehavior *jumpBehavior;
};

// Encapsulated kick behaviors (as an interface)
class KickBehavior {
public:
	virtual void kick() = 0;
};

class LightningKick : public KickBehavior {
public:
	void kick() override {
		std::cout << "Lightning Kick" << "\n";
	}
};

class TornadoKick : public KickBehavior {
public:
	void kick() override {
		std::cout << "Tornado Kick" << "\n";
	}
};

// Encapsulated jump behaviors (as an interface)
class JumpBehavior {
public:
	virtual void jump() = 0;
};

class ShortJump : public JumpBehavior {
public:
	void jump() override {
		std::cout << "Short Jump" << "\n";
	}
};

class LongJump : public JumpBehavior {
public:
	void jump() override {
		std::cout << "Long Jump" << "\n";
	}
};

// Characters 
class Ryu :public Fighter {
public:
	Ryu(KickBehavior *kickBehavior, JumpBehavior *jumpBehavior): Fighter(kickBehavior,jumpBehavior){}

	void display() override	{
		std::cout << "Ryu" << "\n";
	}
};

class Ken : public Fighter{
public:
	Ken(KickBehavior *kickBehavior, JumpBehavior *jumpBehavior):Fighter(kickBehavior, jumpBehavior) {	}
	
	void display() override{
		std::cout << "Ken" << "\n";
	}
};

class ChunLi : public Fighter{
public:
	ChunLi(KickBehavior *kickBehavior,JumpBehavior *jumpBehavior):Fighter(kickBehavior, jumpBehavior)
	{}
	void display() override	{
		std::cout << "ChunLi" << "\n";
	}
};


// Driver class 
int main() {

	// let us make some behaviors first 
	JumpBehavior *shortJump = new ShortJump();
	JumpBehavior *longJump = new LongJump();
	KickBehavior *tornadoKick = new TornadoKick();

	// Make a fighter with desired behaviors 
	Fighter *ken = new Ken(tornadoKick, shortJump);
	ken->display();

	// Test behaviors 
	ken->punch();
	ken->kick();
	ken->jump();

	// Change behavior dynamically (algorithms are interchangeable) 
	ken->setJumpBehavior(longJump);
	ken->jump();

	return EXIT_SUCCESS;
}

#endif // BEHAVIORAL_STRATEGY_EXAMPLE_II 