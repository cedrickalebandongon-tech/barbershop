#include <iostream>
#include <cstdlib>

using namespace std;

// Define the structure of one node
struct Node
{
    int year;           // Stores the year released
    string album;       // Stores the album name
    string singer;      // Stores the singer name
    string title;       // Stores the song title
    Node* next;         // Stores the address of the next node
};

// FUNCTION TO DISPLAY THE SONG PLAYLIST
void displayPlaylist(Node* head)
{
    cout << "========================================" << endl;
    cout << "             MUSIC PLAYLIST             " << endl;
    cout << "========================================" << endl;

    // Check if the playlist is empty
    if (head == nullptr)
    {
        cout << "Playlist is empty." << endl;
    }
    else
    {
        cout << "No.\tYear\tAlbum\tSinger\tSong Title" << endl;

        // Start traversal from head
        Node* current = head;

        // Automatically generate the song number
        int no = 1;

        // Traverse the linked list
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
    // DECLARE HEAD
    // The playlist is initially empty
    Node* head = nullptr;
    int songCount = 0;

    // CREATE THE FIRST SONG

    // Step 1: Create the first node
    Node* first = new Node;

    cout << "CREATE MUSIC PLAYLIST" << endl;

    // Step 2: Get the details of the first song
    cout << endl << "Enter song year: ";
    cin >> first->year;
    cin.ignore();

    cout << "Enter song album: ";
    getline(cin, first->album);

    cout << "Enter song singer: ";
    getline(cin, first->singer);

    cout << "Enter song title: ";
    getline(cin, first->title);

    // Step 3: The first song is currently the last song
    first->next = nullptr;

    // Step 4: Head points to the first song
    head = first;
    songCount++;

    // DISPLAY THE PLAYLIST
    displayPlaylist(head);

    // Pointer used for traversal
    Node* current = nullptr;

    // MENU
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

        // 1. ADD SONG AT THE END
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

            // New node becomes the last node
            newNode->next = nullptr;

            // Check if the playlist is empty
            if (head == nullptr)
            {
                head = newNode;
            }
            else
            {
                // Traverse to the last node
                current = head;

                while (current->next != nullptr)
                {
                    current = current->next;
                }

                // Connect the last node to the new node
                current->next = newNode;
            }

            songCount++;

            displayPlaylist(head);
        }

        // 2. INSERT SONG AT A POSITION
        else if (choice == 2)
        {
            int position;

            cout << endl
                 << "Enter position to insert (1-"
                 << songCount + 1 << "): ";
            cin >> position;

            // Check if the position is valid
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

                // INSERT AT THE BEGINNING
                if (position == 1)
                {
                    newNode->next = head;
                    head = newNode;
                }

                // INSERT AT THE MIDDLE OR END
                else
                {
                    // Find the node before the insertion position
                    current = head;

                    for (int i = 1; i < position - 1; i++)
                    {
                        current = current->next;
                    }

                    // New node points to the next node
                    newNode->next = current->next;

                    // Previous node points to the new node
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

        // 3. REMOVE SONG AT A POSITION
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
                    // REMOVE THE FIRST SONG
                    if (position == 1)
                    {
                        Node* temp = head;

                        head = head->next;

                        delete temp;
                    }

                    // REMOVE FROM MIDDLE OR END
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

        // 4. SEARCH SONG
// 4. SEARCH SONG
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

        // SEARCH BY YEAR
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

        // SEARCH BY ALBUM
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

        // SEARCH BY SINGER
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

        // SEARCH BY SONG TITLE
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

        // INVALID SEARCH CHOICE
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}

        // 5. DISPLAY SONG PLAYLIST
        else if (choice == 5)
        {
            displayPlaylist(head);
        }

        // 6. EXIT
        else if (choice == 6)
        {
            cout << "====================================================" << endl;
            cout << "Thanks for using music playlist, see u next time!" << endl;
            cout << "====================================================" << endl;
        }

        // INVALID MENU CHOICE
        else
        {
            cout << "Invalid choice." << endl;
        }

    } while (choice != 6);

    // RELEASE MEMORY
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