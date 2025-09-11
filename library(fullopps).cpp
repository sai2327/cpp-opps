#include<bits/stdc++.h>
using namespace std;

class Book{
    public:
    string title;
    string author;
    string genre;
    int id;
    int available_copies;
    Book(int i,string t,string a,string genre, int ac){
        title = t;
        this->genre = genre;
        author = a;
        id = i;
        available_copies = ac;
    }
    void Display(){
        cout<<"ID: "<<id<<", Title: "<<title<<", Author: "<<author<<"genre"<<genre<<", Available Copies: "<<available_copies<<endl;
    }
};
class Member{
    public:
    string name;
    int member_id;
    string phoneNumber;
    vector<int> borrowed_ids;   // store only book IDs

    Member(int id,string n,string ph){
        member_id=id;
        name=n;
        phoneNumber=ph;
    }

    void borrowBook(Book &b){
        if(b.available_copies>0){
            borrowed_ids.push_back(b.id);
            b.available_copies--;
            cout<<name<<" borrowed "<<b.title<<endl;
            cout<<b.available_copies<<endl;
        }else{
            cout<<b.title<<" is not available right now."<<endl;
        }
    }

    bool returnBook(int bookId){
        auto it=find(borrowed_ids.begin(),borrowed_ids.end(),bookId);
        if(it!=borrowed_ids.end()){
            borrowed_ids.erase(it);
            return true;  // success
        }
        return false; // fail
    }

};

class Library{
    public:
    vector<Book> books;
    vector<Member> members;
    void addBook(Book &b){
        books.push_back(b);
    }
    void addMember(Member &m){
        members.push_back(m);
    }
    void borrowBook(int memberId,int bookId){
        for(auto &b:books){
            if(b.id==bookId){
                for(auto& m:members){
                    if(m.member_id==memberId){
                        m.borrowBook(b);
                        return;
                    }
                }
            }
        }
    }
    void returnBook(int memberId,int bookId){
        for(auto &b:books){
            if(b.id==bookId){
                for(auto& m:members){
                    if(m.returnBook(bookId)){
                        b.available_copies++;
                        cout<<m.name<<" returned "<<b.title<<endl;
                    }
                    else{
                        cout<<m.name<<" did not borrow book with ID "<<bookId<<endl;
                    }
                    return;
                }
            }
        }
    }
    void showAvailableCount(int bookId){
        for(auto & b:books){
            if(b.id==bookId){
                cout<<"available copies:"<<b.available_copies<<endl;
            }
        }
    }
};
int main(){
    Library lib;
    Book b1(1,"c++ using opps","Sai","c++",2);
    lib.addBook(b1);
    Member m1(1,"sai","8985649779");
    lib.addMember(m1);
    lib.borrowBook(1,1);
    lib.borrowBook(1,1);
    lib.borrowBook(1,1);
    lib.borrowBook(1,1);
    lib.showAvailableCount(1);
    lib.returnBook(1,1);
    lib.returnBook(1,1);
    lib.showAvailableCount(1);
}
