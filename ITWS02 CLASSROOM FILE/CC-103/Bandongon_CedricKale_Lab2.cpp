#include <iostream>
#include <cstdlib>

using namespace std;

// struc of node
struct Node
{
    int year;           // year release
    string album;       // album name
    string singer;      // singer name
    string title;       // song title
    Node* next;         // address of the next node
};

// function for displayPlaylist
void displayPlaylist(Node* head)
{
    cout << "========================================" << endl;
    cout << "             MUSIC PLAYLIST             " << endl;
    cout << "========================================" << endl;

    // for empty playlist
    if (head == nullptr)
    {
        cout << "Playlist is empty." << endl;
    }
    else
    {
        cout << "No.\tYear\tAlbum\tSinger\tSong Title" << endl;

        // head traversal
        Node* current = head;

        // song number
        int no = 1;

        // linked list traversal
        while (current != nullptr)
        {
            cout << no << "\t"
                 << current->year << "\t"
                 << current->album << "\t"
                 << current->singer << "\t"
                 << current->title << endl;

            current = current->next;
            no++;
        }
    }
}

int main()
{
    // declaration of the head
    // initially playlist is empty
    Node* head = nullptr;
    int songCount = 0;
    Node* first = new Node;

    cout << "CREATE MUSIC PLAYLIST" << endl;

    cout << endl << "Enter song year: ";
    cin >> first->year;
    cin.ignore();

    cout << "Enter song album: ";
    getline(cin, first->album);

    cout << "Enter song singer: ";
    getline(cin, first->singer);

    cout << "Enter song title: ";
    getline(cin, first->title);

    first->next = nullptr;

    head = first;
    songCount++;

    //will display the output
    displayPlaylist(head);

    Node* current = nullptr;

    //menu option naten to sir
    int choice;

    do
    {
        cout << endl << "MUSIC PLAYLIST MENU" << endl;
        cout << "1. Add Song at the End" << endl;
        cout << "2. Insert Song at a Position" << endl;
        cout << "3. Remove Song at a Position" << endl;
        cout << "4. Search Song" << endl;
        cout << "5. Display Song Playlist" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        //song tat the end command
        if (choice == 1)
        {
            Node* newNode = new Node;

            cout << endl << "Enter song year: ";
            cin >> newNode->year;
            cin.ignore();

            cout << "Enter album title: ";
            getline(cin, newNode->album);

            cout << "Enter singer: ";
            getline(cin, newNode->singer);

            cout << "Enter song title: ";
            getline(cin, newNode->title);

            // latest node you add becomes the last node
            newNode->next = nullptr;

            // for empty checking
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                // last node
                current = head;

                while (current->next != nullptr)
                {
                    current = current->next;
                }

                current->next = newNode;
            }

            songCount++;

            displayPlaylist(head);
        }

        // 2. new song to any place you want
        else if (choice == 2)
        {
            int position;

            cout << endl
                 << "Enter position to insert (1-"
                 << songCount + 1 << "): ";
            cin >> position;

            if (position >= 1 && position <= songCount + 1)
            {
                Node* newNode = new Node;

                cout << "Enter year: ";
                cin >> newNode->year;
                cin.ignore();

                cout << "Enter album title: ";
                getline(cin, newNode->album);

                cout << "Enter singer: ";
                getline(cin, newNode->singer);

                cout << "Enter song title: ";
                getline(cin, newNode->title);

                // beggining insertion
                if (position == 1)
                {
                    newNode->next = head;
                    head = newNode;
                }

                // gitna or dulo insertion
                else
                {
                    current = head;

                    for (int i = 1; i < position - 1; i++)
                    {
                        current = current->next;
                    }
                    newNode->next = current->next;

                    current->next = newNode;
                }

                songCount++;

                displayPlaylist(head);
            }
            else
            {
                cout << "Invalid position." << endl;
            }
        }

        // 3. remove song from the position if you dont want it anymore
        else if (choice == 3)
        {
            if (head == nullptr)
            {
                cout << endl << "The song playlist is empty." << endl;
            }
            else
            {
                int position;

                cout << endl
                     << "Enter position to remove (1-"
                     << songCount << "): ";
                cin >> position;

                if (position >= 1 && position <= songCount)
                {
                    // delete/remove the first song you added 
                    if (position == 1)
                    {
                        Node* temp = head;

                        head = head->next;

                        delete temp;
                    }

                    // delete/remove middle or end song
                    else
                    {
                        current = head;

                        for (int i = 1; i < position - 1; i++)
                        {
                            current = current->next;
                        }
                        Node* temp = current->next;
                        current->next = temp->next;
                        delete temp;
                    }

                    songCount--;

                    displayPlaylist(head);
                }
                else
                {
                    cout << "Invalid position." << endl;
                }
            }
        }
// 4. song searching
else if (choice == 4)
{
    if (head == nullptr)
    {
        cout << endl << "The music playlist is empty." << endl;
    }
    else
    {
        int searchChoice;

        cout << endl << "SEARCH SONG" << endl;
        cout << "1. Search by Year" << endl;
        cout << "2. Search by Album" << endl;
        cout << "3. Search by Singer" << endl;
        cout << "4. Search by Song Title" << endl;

        cout << "Enter choice: ";
        cin >> searchChoice;

        // year search
        if (searchChoice == 1)
        {
            int searchYear;

            cout << "Enter year to search: ";
            cin >> searchYear;

            current = head;
            int no = 1;
            bool found = false;

            cout << endl << "SEARCH RESULT" << endl;
            cout << "No.\tYear\tAlbum\tSinger\tSong Title" << endl;

            while (current != nullptr)
            {
                if (current->year == searchYear)
                {
                    cout << no << "\t"
                         << current->year << "\t"
                         << current->album << "\t"
                         << current->singer << "\t"
                         << current->title << endl;

                    found = true;
                }

                current = current->next;
                no++;
            }

            if (found == false)
            {
                cout << "No song found for year "
                     << searchYear << "." << endl;
            }
        }

        // album search
        else if (searchChoice == 2)
        {
            string searchAlbum;

            cin.ignore();

            cout << "Enter album: ";
            getline(cin, searchAlbum);

            current = head;
            int no = 1;
            bool found = false;

            cout << endl << "SEARCH RESULT" << endl;
            cout << "No.\tYear\tAlbum\tSinger\tSong Title" << endl;

            while (current != nullptr)
            {
                if (current->album.find(searchAlbum) != string::npos)
                {
                    cout << no << "\t"
                         << current->year << "\t"
                         << current->album << "\t"
                         << current->singer << "\t"
                         << current->title << endl;

                    found = true;
                }

                current = current->next;
                no++;
            }

            if (found == false)
            {
                cout << "No song found in album \""
                     << searchAlbum << "\"." << endl;
            }
        }

        // taga kanta search
        else if (searchChoice == 3)
        {
            string searchSinger;

            cin.ignore();

            cout << "Enter singer: ";
            getline(cin, searchSinger);

            current = head;
            int no = 1;
            bool found = false;

            cout << endl << "SEARCH RESULT" << endl;
            cout << "No.\tYear\tAlbum\tSinger\tSong Title" << endl;

            while (current != nullptr)
            {
                if (current->singer.find(searchSinger) != string::npos)
                {
                    cout << no << "\t"
                         << current->year << "\t"
                         << current->album << "\t"
                         << current->singer << "\t"
                         << current->title << endl;

                    found = true;
                }

                current = current->next;
                no++;
            }

            if (found == false)
            {
                cout << "No song found for singer \""
                     << searchSinger << "\"." << endl;
            }
        }

        // pangaln ng kanta search
        else if (searchChoice == 4)
        {
            string searchTitle;

            cin.ignore();

            cout << "Enter song title: ";
            getline(cin, searchTitle);

            current = head;
            int no = 1;
            bool found = false;

            cout << endl << "SEARCH RESULT" << endl;
            cout << "No.\tYear\tAlbum\tSinger\tSong Title" << endl;

            while (current != nullptr)
            {
                if (current->title.find(searchTitle) != string::npos)
                {
                    cout << no << "\t"
                         << current->year << "\t"
                         << current->album << "\t"
                         << current->singer << "\t"
                         << current->title << endl;

                    found = true;
                }

                current = current->next;
                no++;
            }

            if (found == false)
            {
                cout << "No song found with the title \""
                     << searchTitle << "\"." << endl;
            }
        }

        // invalid choice search
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}

        // 5. display song playlist mo na ginawa 
        else if (choice == 5)
        {
            displayPlaylist(head);
        }

        // 6. Exit of the program
        else if (choice == 6)
        {
            cout << "====================================================" << endl;
            cout << "Thanks for using music playlist, see u next time!" << endl;
            cout << "====================================================" << endl;
        }

        // invalid nanaman 
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    // release of the memory 
    current = head;

    while (current != nullptr)
    {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    head = nullptr;
    first = nullptr;
    current = nullptr;

    return EXIT_SUCCESS;
} 