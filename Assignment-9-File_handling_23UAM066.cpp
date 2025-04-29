#include<iostream>
#include<fstream>
using namespace std;

class FileEncryptor{
    private:
        string filename;
        int encryptionKey;
        int i;

    public:
        FileEncryptor(string fileName, int key){
            filename = fileName;
            encryptionKey = key;
        }

        void encryptAndWrite(string message){
            ofstream file(filename);
            if(!file){
                cout<<"Error while opening file."<<endl;  //File opening error
                return;
            }

            for(i=0;i<message.length();i++){
                char ch=message[i];
                if(isalpha(ch)){
                    char base = isupper(ch) ? 'A' : 'a'; //If character of content is uppercase the "A" else "a"
                    ch = (ch-base+encryptionKey)%26 +base;
                }
                file<<ch;
            }

            file.close();
            cout<<"Message successfully encrypted and stored in "<<filename<<endl;
        }

        string readAndDecrypt(){
            ifstream file(filename);
            if(!file){
                cout << "Error while opening file:" << endl; //File opening
                return "file opening error";
            }

            string decryptedMessage ="";
            char ch;
            while(file.get(ch)){
                if(isalpha(ch)){
                    char base = isupper(ch) ? 'A' : 'a';
                    ch=(ch-base- encryptionKey + 26)%26 +base;  //If character of content is uppercase the "A" else "a"
                }
                decryptedMessage=decryptedMessage+ch;
            }
            file.close();
            return decryptedMessage;
        }

        // Display function to display content of file
        void displayContent(){
            cout<<"Reading and decrypting file..."<<endl;
            string content = readAndDecrypt(); // Call function for decryption
            cout <<"Decrypted content: "<<content<<endl;
        }
};

int main(){
    FileEncryptor encryptor("data.txt", 4);
    int ch;
    string msg;

    do{
        cout<<"\n1.Encrypt and Write to File."<<endl;
        cout<<"2.Read and Decrypt File"<<endl;
        cout<<"3.Exit"<<endl;
        cout<<"Enter your choice: ";
        cin >> ch;
//        cin.ignore();

        if(ch == 1){
            cout<<"Enter the message for encryption: ";
            getline(cin, msg);
            encryptor.encryptAndWrite(msg);
        }
        else if(ch == 2){
            encryptor.displayContent();
        }
    }while(choice != 3);

    return 0;
}

