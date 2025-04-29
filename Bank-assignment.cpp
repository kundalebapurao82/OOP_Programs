#include<iostream>
using namespace std;
#include<cstring>
class Book{
	private:
		char* bookTitle;
		char* AuthName;
		int pageCount;
		bool formatType ;
		float *chapterPages;
		int numberOfChapters;
		float tempPages;
		int i;
	public:
		Book(){
			bookTitle = new char[1];
			bookTitle[0] = '\0';
			AuthName = new char[1];
			AuthName[0] = '\0';
			pageCount = 0;
			numberOfChapters = 0;
			formatType = false;
			chapterPages = NULL;
			chapterPages = 0;
			
		}
		
		Book(char* title, char* auth, int pCount, bool b, int nChapters){
			bookTitle = new char[strlen(title)+1];
			strcpy(bookTitle, title);
			AuthName = new char[strlen(auth)+1];
			strcpy(AuthName, auth);
			pageCount = pCount;
			numberOfChapters = nChapters;
			if(numberOfChapters > 0){
				chapterPages = new float[numberOfChapters];
				tempPages = pageCount / numberOfChapters;
				for (i = 0; i < numberOfChapters; i++){
	                chapterPages[i] = tempPages;
	            }
	    	}
			else{
		        chapterPages = NULL;
			}
			
		}
		
		Book(const Book& obj){
			bookTitle = new char[strlen(obj.bookTitle)+1];
			bookTitle = obj.bookTitle;
			AuthName = new char[strlen(obj.AuthName)+1];
			AuthName = obj.AuthName;
			pageCount = obj.pageCount;
			numberOfChapters = obj.numberOfChapters;
			if(obj.numberOfChapters != NULL){
				chapterPages = new float[numberOfChapters];
				//tempPages = pageCount / numberOfChapters;
				for (i = 0; i < numberOfChapters; i++){
	                chapterPages[i] = obj.chapterPages[i];
	            }
	    	}
			else{
		        chapterPages = NULL;
			}
		}
		void Display(){
			cout<<"\nBook title  : "<<bookTitle;
			cout<<"\nAuthor : "<<AuthName;
			cout<<"\nTotal pages : "<<pageCount;
			cout<<"\nFormat : "<<(formatType ? "Hardcover" : "paperback");
			cout<<"\nNumber of chapters : "<<numberOfChapters;
			if(numberOfChapters>0){
				cout<<"\nChapterWise pages : ";
				for(i=0;i<numberOfChapters;i++){
					cout<<"\nChapter "<<i+1<<" : "<<chapterPages[i]<<" Pages."<<endl;
				}
			}
		}
		~Book(){
			delete bookTitle;
			delete AuthName;
			delete chapterPages;
		}
};
int main(){
	Book b1;
	b1.Display();
	
	Book b2("Agnipankh", "Dr. A. P. J. Abdul Kalam", 630, true, 5);
	b2.Display();
	
	Book b3 = b2;
	b3.Display();
}
