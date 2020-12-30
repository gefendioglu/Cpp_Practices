#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string> 
#include<vector> 

// http://www.vishalchovatiya.com/strategy-design-pattern-in-modern-cpp/
// Dynamic Strategy - TO BE COMPLETED
// ----------------------------------------------
//enum class Format { Markdown, Html };
//
//// Base Class
//class ListStrategy {
//public:
//    virtual ~ListStrategy() = default;
//    virtual void add_list_item(std::ostream& oss, std::string& item) {};
//    virtual void start(std::ostream& oss) {};
//    virtual void end(std::ostream& oss) {};
//};
//
//// Derived Class
//class MarkdownListStrategy : public ListStrategy {
//public:
//    void add_list_item(std::ostream& oss, std::string& item) override { oss << " - " << item << "\n"; }
//};
//
//// Derived Class
//class HtmlListStrategy : public ListStrategy {
//    void start(std::ostream& oss) override { 
//        oss << "<ul>" << "\n"; 
//    }
//
//    void end(std::ostream& oss) override { 
//        oss << "</ul>" << "\n";
//    }
//
//    void add_list_item(std::ostream& oss, std::string& item) override{
//        oss << "\t<li>" << item << "</li>" << "\n";
//    }
//};
//
//class TextProcessor {
//public:
//
//    void clear() {
//        //m_oss.str("");
//        m_oss.clear();
//    }
//
//    void append_list(std::vector<std::string>& items) {
//        
//        m_list_strategy->start(m_oss);
//        
//        for (auto& item : items)
//            m_list_strategy->add_list_item(m_oss, item);
//       
//        m_list_strategy->end(m_oss);
//    }
//
//    void set_output_format(Format& format) {
//        switch (format) {
//        case Format::Markdown: m_list_strategy = std::make_unique<MarkdownListStrategy>(); break;
//        case Format::Html: m_list_strategy = std::make_unique<HtmlListStrategy>(); break;
//        }
//    }
//
//    //std::string str() { return m_oss.str(); }
//
//private:
//    std::ostream m_oss;
//    std::unique_ptr<ListStrategy> m_list_strategy;
//};
//
//int main() {
//    // markdown
//    TextProcessor tp;
//    tp.set_output_format(Format::Markdown);
//    tp.append_list({ "foo", "bar", "baz" });
//    std::cout << tp.str() << "\n";
//
//    // html
//    tp.clear();
//    tp.set_output_format(Format::Html);
//    tp.append_list({ "foo", "bar", "baz" });
//    std::cout << tp.str() << "\n";
//
//    return EXIT_SUCCESS;
//    
//    /*
//     - foo
//    - bar
//    - baz
//
//    <ul>
//        <li>foo</li>
//        <li>bar</li>
//        <li>baz</li>
//    </ul>
//    */
//}


// ----------------------------------------------
// ----------------------------------------------

// Strategy Pattern - GeeksForGeeks - TO BE CONTROLLED !!!

//// Abstract as you must have a specific fighter 
//class Fighter {
//public:
//	// Constructor
//	Fighter(KickBehavior *kickBehavior,JumpBehavior *jumpBehavior){
//		this->jumpBehavior = jumpBehavior;
//		this->kickBehavior = kickBehavior;
//	}
//
//	void punch(){
//		std::cout << "Default Punch" << "\n";
//	}
//
//	void kick(){
//		// delegate to kick behavior 
//		kickBehavior->kick();
//	}
//
//	void jump(){
//		// delegate to jump behavior 
//		jumpBehavior->jump();
//	}
//
//	void roll()	{
//		std::cout << "Default Roll" << "\n";
//	}
//
//	void setKickBehavior(KickBehavior *kickBehavior)
//	{
//		this->kickBehavior = kickBehavior;
//	}
//
//	void setJumpBehavior(JumpBehavior *jumpBehavior)
//	{
//		this->jumpBehavior = jumpBehavior;
//	}
//
//	virtual void display()=0;
//
//private:
//	KickBehavior *kickBehavior;
//	JumpBehavior *jumpBehavior;
//};
//
//// Encapsulated kick behaviors (as an interface)
//class KickBehavior {
//public:
//	virtual void kick() = 0;
//};
//
//class LightningKick : public KickBehavior {
//public:
//	void kick() override {
//		std::cout << "Lightning Kick" << "\n";
//	}
//};
//
//class TornadoKick : public KickBehavior {
//public:
//	void kick() override {
//		std::cout << "Tornado Kick" << "\n";
//	}
//};
//
//// Encapsulated jump behaviors (as an interface)
//class JumpBehavior {
//public:
//	virtual void jump() = 0;
//};
//
//class ShortJump : public JumpBehavior {
//public:
//	void jump() override {
//		std::cout << "Short Jump" << "\n";
//	}
//};
//
//class LongJump : public JumpBehavior {
//public:
//	void jump() override {
//		std::cout << "Long Jump" << "\n";
//	}
//};
//
//// Characters 
//class Ryu :public Fighter {
//public:
//	Ryu(KickBehavior *kickBehavior, JumpBehavior *jumpBehavior): Fighter(kickBehavior,jumpBehavior){}
//
//	void display() override	{
//		std::cout << "Ryu" << "\n";
//	}
//};
//
//class Ken : public Fighter{
//public:
//	Ken(KickBehavior *kickBehavior, JumpBehavior *jumpBehavior):Fighter(kickBehavior, jumpBehavior) {	}
//	
//	void display() override{
//		std::cout << "Ken" << "\n";
//	}
//};
//
//class ChunLi : public Fighter{
//public:
//	ChunLi(KickBehavior *kickBehavior,JumpBehavior *jumpBehavior):Fighter(kickBehavior, jumpBehavior)
//	{}
//	void display() override	{
//		std::cout << "ChunLi" << "\n";
//	}
//};
//
//
//// Driver class 
//int main() {
//
//	// let us make some behaviors first 
//	JumpBehavior *shortJump = new ShortJump();
//	JumpBehavior *LongJump = new LongJump();
//	KickBehavior *tornadoKick = new TornadoKick();
//
//	// Make a fighter with desired behaviors 
//	Fighter *ken = new Ken(tornadoKick, shortJump);
//	ken->display();
//
//	// Test behaviors 
//	ken->punch();
//	ken->kick();
//	ken->jump();
//
//	// Change behavior dynamically (algorithms are interchangeable) 
//	ken->setJumpBehavior(LongJump);
//	ken->jump();
//
//	return EXIT_SUCCESS;
//}
