#define _CRT_SECURE_NO_WARNINGS
#include<iostream> 
#include<string> 

enum class BookFormat {
    HARDCOVER,
    PAPERBACK,
    AUDIO_BOOK,
    EBOOK,
    NEWSPAPER,
    MAGAZINE,
    JOURNAL
};

enum class BookStatus {
    AVAILABLE,
    RESERVED,
    LOANED,
    LOST
};

enum class ReservationStatus {
    WAITING,
    PENDING,
    CANCELED,
    NONE
};

enum class AccountStatus {
    ACTIVE,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    NONE
};

class Address {
public:
private:
    std::string streetAddress;
    std::string city;
    std::string state;
    std::string zipCode;
    std::string country;
};

class Person {
public:
private:
    std::string name;
    Address address;
    std::string email;
    std::string phone;
};

class Constants {
public:
    static const int MAX_BOOKS_ISSUED_TO_A_USER = 5;
    static const int MAX_LENDING_DAYS = 10;
};

// ------------------------------------------------------------------
// ------------------------------------------------------------------

// For simplicity, we are not defining getter and setter functions. The reader can assume that all class attributes are private and accessed through their respective public getter methods and modified only through their public methods function.

class Account {
public:
    bool resetPassword();
private:
    std::string id;
    std::string password;
    AccountStatus status;
    Person person;
};

class Librarian: public Account {
public:
    bool addBookItem(BookItem bookItem);

    bool blockMember(Member member);

    bool unBlockMember(Member member);
};

class Member :public Account {


    public int getTotalBooksCheckedout();

    public boolean reserveBookItem(BookItem bookItem);

    private void incrementTotalBooksCheckedout();

    public boolean checkoutBookItem(BookItem bookItem) {
        if (this.getTotalBooksCheckedOut() >= Constants.MAX_BOOKS_ISSUED_TO_A_USER) {
            ShowError("The user has already checked-out maximum number of books");
            return false;
        }
        BookReservation bookReservation = BookReservation.fetchReservationDetails(bookItem.getBarcode());
        if (bookReservation != null && bookReservation.getMemberId() != this.getId()) {
            // book item has a pending reservation from another user
            ShowError("This book is reserved by another member");
            return false;
        }
        else if (bookReservation != null) {
            // book item has a pending reservation from the give member, update it
            bookReservation.updateStatus(ReservationStatus.COMPLETED);
        }

        if (!bookItem.checkout(this.getId())) {
            return false;
        }

        this.incrementTotalBooksCheckedout();
        return true;
    }

    private void checkForFine(String bookItemBarcode) {
        BookLending bookLending = BookLending.fetchLendingDetails(bookItemBarcode);
        Date dueDate = bookLending.getDueDate();
        Date today = new Date();
        // check if the book has been returned within the due date
        if (today.compareTo(dueDate) > 0) {
            long diff = todayDate.getTime() - dueDate.getTime();
            long diffDays = diff / (24 * 60 * 60 * 1000);
            Fine.collectFine(memberId, diffDays);
        }
    }

    public void returnBookItem(BookItem bookItem) {
        this.checkForFine(bookItem.getBarcode());
        BookReservation bookReservation = BookReservation.fetchReservationDetails(bookItem.getBarcode());
        if (bookReservation != null) {
            // book item has a pending reservation
            bookItem.updateBookItemStatus(BookStatus.RESERVED);
            bookReservation.sendBookAvailableNotification();
        }
        bookItem.updateBookItemStatus(BookStatus.AVAILABLE);
    }

    public bool renewBookItem(BookItem bookItem) {
        this.checkForFine(bookItem.getBarcode());
        BookReservation bookReservation = BookReservation.fetchReservationDetails(bookItem.getBarcode());
        // check if this book item has a pending reservation from another member
        if (bookReservation != null && bookReservation.getMemberId() != this.getMemberId()) {
            ShowError("This book is reserved by another member");
            member.decrementTotalBooksCheckedout();
            bookItem.updateBookItemState(BookStatus.RESERVED);
            bookReservation.sendBookAvailableNotification();
            return false;
        }
        else if (bookReservation != null) {
            // book item has a pending reservation from this member
            bookReservation.updateStatus(ReservationStatus.COMPLETED);
        }
        BookLending.lendBook(bookItem.getBarCode(), this.getMemberId());
        bookItem.updateDueDate(LocalDate.now().plusDays(Constants.MAX_LENDING_DAYS));
        return true;
    }
private:
    Date dateOfMembership;
    int totalBooksCheckedout;
};

// ------------------------------------------------------------------
// ------------------------------------------------------------------


public class BookReservation {
    private Date creationDate;
    private ReservationStatus status;
    private String bookItemBarcode;
    private String memberId;

    public static BookReservation fetchReservationDetails(String barcode);
}

public class BookLending {
    private Date creationDate;
    private Date dueDate;
    private Date returnDate;
    private String bookItemBarcode;
    private String memberId;

    public static boolean lendBook(String barcode, String memberId);
    public static BookLending fetchLendingDetails(String barcode);
}

public class Fine {
    private Date creationDate;
    private double bookItemBarcode;
    private String memberId;

    public static void collectFine(String memberId, long days) {}
}

// ------------------------------------------------------------------
// ------------------------------------------------------------------

class Book {
private:
    String ISBN;
    String title;
    String subject;
    String publisher;
    String language;
    int numberOfPages;
    List<Author> authors;
};

class BookItem : public Book {
    public boolean checkout(String memberId) {
        if (bookItem.getIsReferenceOnly()) {
            ShowError("This book is Reference only and can't be issued");
            return false;
        }
        if (!BookLending.lendBook(this.getBarCode(), memberId)) {
            return false;
        }
        this.updateBookItemStatus(BookStatus.LOANED);
        return true;
    }
private:
    String barcode;
    bool isReferenceOnly;
    Date borrowed;
    Date dueDate;
    double price;
    BookFormat format;
    BookStatus status;
    Date dateOfPurchase;
    Date publicationDate;
    Rack placedAt;
};

class Rack {
public:
private:
    int number;
    std::string locationIdentifier;
};


// ------------------------------------------------------------------
// ------------------------------------------------------------------

public interface Search {
    public List<Book> searchByTitle(String title);
    public List<Book> searchByAuthor(String author);
    public List<Book> searchBySubject(String subject);
    public List<Book> searchByPubDate(Date publishDate);
}

public class Catalog implements Search {
    private HashMap<String, List<Book>> bookTitles;
    private HashMap<String, List<Book>> bookAuthors;
    private HashMap<String, List<Book>> bookSubjects;
    private HashMap<String, List<Book>> bookPublicationDates;

    public List<Book> searchByTitle(String query) {
        // return all books containing the string query in their title.
        return bookTitles.get(query);
    }

    public List<Book> searchByAuthor(String query) {
        // return all books containing the string query in their author's name.
        return bookAuthors.get(query);
    }
}


//int main() {
//
//    return EXIT_SUCCESS;
//}