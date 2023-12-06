// Title: Movie Recomendation System

// library file for input and output function
#include <iostream>
// library file for string data type
#include <string>
// library file for vector function
#include <vector>
// library file limit function
#include<limits>
// library file for filehandling
#include<fstream>
using namespace std;

//  class
class Movie 
{
// access specifier
public:
    // attributes
    string name;
    string genre;

    // parametrized constructor
    Movie(string n, string g)
    {
        name = n;
        genre = g;

    }

    // setter
    string setName(string n)
    {
        name = n;
    }

    // setter 
    string setGenre(string g)
    {
        genre = g;
    }


    // getter
    string getName() const
    {
        return name;
    }

    // getter
    string getGenre() const 
    {
        return genre;
    }
};


// 2nd class also parent class for inheritance
class MovieCollection 
{
// access specifier
public:
    // vector for class movie
    vector<Movie> m;
    
    // function declaration for adding movie
    void addMovie(string name, string genre)
    {
        Movie movie(name, genre);

        // push back function
        m.push_back(movie);

       
      
    }

    // vector for getting movies by name
    vector<Movie> getMoviesByName(const string& name) 
    {
        // vector for class movie to store names
        vector<Movie> result;

        // for loop
        for (auto& movie : m)
        {
            // if condition
            if (movie.getName() == name) 
            {
                // push back function
                result.push_back(movie);
            }
        }
        return result;
    }

    //  vector for getting movies genre
    vector<Movie> getMoviesByGenre(const string& genre) 
    {
        // vector for class movie to store genre
        vector<Movie> result;

        // for loop
        for (auto& movie : m) 
        {
            // if condition
            if (movie.getGenre() == genre)
            {
                // push back function
                result.push_back(movie);
            }
        }
        return result;
    }

    // vector for storing allmovies
    vector<Movie> getAllMovies() 
    {
        return m;
    }

};

// child class inheriated by moviecollection
class Ratings :public MovieCollection
{
// access specifier
public:

    // vector used for Rating class
    vector<Ratings> rate;

    // attribute
    int rating;

    // constructor
    Ratings()
    {
        rating = 0;

    }

    // parametrized constructor
    Ratings(int a)
    {
        rating = a;

    }

    // function declaration for rating movie
    void Rating()
    {
        // attribute
        int R1;
        cout << "how much would you rate this movie out of 10: ";
        cin >> R1;

        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> R1;
        }

        // while loop
        while (R1 > 10 || R1 < 0)
        {

            cout << "invalid rating try again: ";
            cin >> R1;

        }

        // function call
        addRating(R1);
        cout << "Rating Updated" << endl;
    }


    // function declaration
    void addRating(const double& val)
    {
        Ratings o10(val);

        // push back function
        rate.push_back(o10);
    
    }

    // vector for storing rating result
    vector<Ratings> getAllRatings() 
    {
        return rate;
    }

    // getter
    int getRating()
    {
        return rating;
    }
};

// Child Class Inherited from Moviecollection
// Inheritance Used: Hierarchical Inheritance 
class Main : public MovieCollection 
{
// access specifier
public:

    // friend class

    friend class Report;

    // creating object for classes
    MovieCollection c;
    Ratings a;

    // file handling
    fstream mDatabase;

    // function declaration
    void initialCreatorSetup()
    {     
            //file creation and database loading to vectors
            
            mDatabase.open("MovieFile.txt", fstream::out);

            mDatabase << "Movie: JawaniPhirNahiAni  Genre: Romantic" << endl;
            c.addMovie("JawaniPhirNahiAni", "romantic");
            a.addRating(8);
            mDatabase << "Movie: MoneyBackGuarntee  Genre: Action" << endl;
            c.addMovie("MoneyBackGuarntee", "Action");
            a.addRating(8);
            mDatabase << "Movie: ChalMeraPutt  Genre: Comedy" << endl;
            c.addMovie("ChalMEraPutt", "Comedy");
            a.addRating(9);
            mDatabase << "Movie: ChalMAxioChalea  Genre: Comedy" << endl;
            c.addMovie("ChalMaxioChalea", "Comedy");
            a.addRating(7);

            mDatabase << "Movie: MyNameIsKhan  Genre: Drama" << endl;
            c.addMovie("MyNameIsKhan", "Drama");
            a.addRating(6);

            mDatabase << "Movie: Dhoom3  Genre: Action" << endl;
            c.addMovie("Dhoom3", "Action");
            a.addRating(8);

            mDatabase << "Movie: Bhagban  Genre: Drama" << endl;
            c.addMovie("Bhagban", "Drama");
            a.addRating(7);

            mDatabase << "Movie: Wrong Number  Genre: Romantic" << endl;
            c.addMovie("Wrong Number", "Romantic");
            a.addRating(9);

            mDatabase << "Movie: Bin Roye  Genre: Romantic" << endl;
            c.addMovie("Bin Roye", "Romantic");
            a.addRating(5);

            mDatabase << "Movie: Mission Impossible  Genre: Action" << endl;
            c.addMovie("Mission Impossible", "Action");
            a.addRating(9);

            mDatabase << "Movie: 3 Idiots  Genre: Comedy" << endl;
            c.addMovie("3 Idoits", "Comedy");
            a.addRating(10);

            mDatabase.close();

            

    }
    
    // virtual function declaration for displaying movie name
    virtual void displayMovieName() 
    {
        // attribute
        string sn;

        cout << "Enter movie name to search: ";
        cin >> sn;
    
        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> sn;
        }
        
        // vector to store movies by name
        vector<Movie> moviesByName = c.getMoviesByName(sn);
        cout << "Movies matching the name \"" << sn << "\":" << endl;
        
        // for loop to display the name and genre of searched movie
            for (auto& movie : moviesByName)
            {
                cout << "Movie: " << movie.getName() << ", Genre: " << movie.getGenre() << endl;
            }
    }

    // virtual function declartaion with arguments
    virtual void displayMovieName(string sn) 
    {
        // vector to store movies by name
        vector<Movie> moviesByName = c.getMoviesByName(sn);
        cout << "Movies matching the name \"" << sn << "\":" << endl;
        
        // for loop to display the name and genre of searched movie
        for (auto& movie : moviesByName) 
        {
            cout << "Movie: " << movie.getName() << ", Genre: " << movie.getGenre() << endl;
        }
    }

    // virtual function declaration to display genre
    virtual void displayMovieGenre()
    {
        // attribute
        string sg;

        cout << "Enter movie genre to search: ";
        cin >> sg;

        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> sg;
        }

        // vector to store movies by genre
        vector<Movie> moviesByGenre = c.getMoviesByGenre(sg);

        cout << "Movies matching the genre \"" << sg << "\":" << endl;

        //for loop
        for (auto& movie : moviesByGenre) 
        {
            cout << "Movie: " << movie.getName() << ", Genre: " << movie.getGenre() << endl;
        }
    }

    
    // virtual function declaration to display genre with argument
    virtual void displayMovieGenre(string sg)
    {
        // vector to store movies by genre
        vector<Movie> moviesByGenre = c.getMoviesByGenre(sg);

        cout << "Movies matching the genre \"" << sg << "\":" << endl;
       
        //for loop
        for (auto& movie : moviesByGenre)
        {
            cout << "Movie: " << movie.getName() << ", Genre: " << movie.getGenre() << endl;
        }
    }


    // virtual function declaration to display all movies stored
    virtual void displayAllMovies() 
    {
        

        // file handling        
        mDatabase.open("MovieFile.txt");
        if (mDatabase.is_open())
        {
            while (!mDatabase.eof())
            {
                string na;
                getline(mDatabase, na);
                cout << na << endl;
            }


        }
        mDatabase.close();
        
        // vector to print rate
        vector<Ratings> allRatings = a.getAllRatings();
       
        // for loop for having rating of all movies
        for (auto& movie : allRatings) 
        {
            cout << "Rating: " << movie.getRating() << endl;
        }

    }


    // menu function declaration
    void menu() 
    {
        // attribute
        int choice;

        // do while loop
        do 
        {
            cout<< "=========================================================================" << endl;
            cout<< "===============     Movie Recommendation System      ====================" << endl;
           
            cout<< "=========================================================================" << endl;
            cout << endl;
            cout << "                       Enter 1 for User Setup" << endl;
            cout << "                       Enter 2 for Updated Setup" << endl;
            cout << "                       Enter 3 to Exit" << endl;


            cout << "Enter your choice: ";
            cin >> choice;

            //validtion loop for cin fail
            while (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits < streamsize > ::max(), '\n');
                cout << "You have entered an invalid input. Try again: ";
                cin >> choice;
            }
            // implemneting switch statment
            switch (choice) 
            {
            case 1:
                initialSetup();
                break;
            case 2:
                updateSetup();
                break;
            case 3:
                cout << "Exiting..." << endl;
                //clear screen ---------------------------------->
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }

            cout << endl;
        } while (choice != 3);

    }

    // function declaration for intail setup
    void initialSetup() 
    {
        // welcoming message for user
        cout << "***************************************************************************" << endl;
        cout << "-------------------------------WELCOME USER--------------------------------" << endl;
        cout << "***************************************************************************" << endl;

        cout << "                              LIST OF MOVIES" << endl;  
        // function call
        displayAllMovies();

        // asking user to enter gnere of any 3 movies from stored data
        cout << "Enter the name of 3 genres you want to see out of these:" << endl;
        string c1, c2, c3;
        cout << "genre 1: ";
        cin >> c1;
        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> c1;
        }

        cout << "genre 2: ";
        cin >> c2;
        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> c2;
        }

        cout << "genre 3: ";
        cin >> c3;
        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> c3;
        }

        // report function call for genre
        reportG(c1, c2, c3);

    }

    // report function declaration for movie genre
    void reportG(string a, string b, string c)
    {
        cout << "Recommended movies: " << endl;
        // func0tion call
        displayMovieGenre(a);
        cout << endl;
        // function call
        displayMovieGenre(b);
        cout << endl;
        // function call
        displayMovieGenre(c);


    }

    // report function declaration for movie names
    void reportM(string a, string b, string c)
    {
        cout << "Recommended movies: " << endl;

        // function call
        displayMovieName(a);
        cout << endl;

        // function call
        displayMovieName(b);
        cout << endl;

        // function call
        displayMovieName(c);

    }

    // function for updating record
    void updateSetup()
    {
        string sa, sb, sc;
        
        // function call
        displayAllMovies();

        cout << "enter the name of 3 movies you have already watched out of this database: " << endl;
        cout << "movie 1: ";
        cin >> sa;
        // function call
        a.Rating();

        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> sa;
        }
        cout << "movie 2: ";
        cin >> sb;
        // function call
        a.Rating();
        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> sb;
        }

        cout << "movie 3: ";
        cin >> sc;
        // function call
        a.Rating();

        //validtion loop for cin fail
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits < streamsize > ::max(), '\n');
            cout << "You have entered an invalid input. Try again: ";
            cin >> sc;
        }
        // function call
        reportM(sa, sb, sc);

    }


};

// class
class Reports
{

public:
    
    // friend functions
    friend void reportG() {};
    friend void reportM() {};
};

// main body
int main() 
{
    //exception handling
    try 
    {
        // creating object of class Main
        Main d;
        d.initialCreatorSetup();
        // function calling
        d.menu();
    }

    catch (const exception& e)
    {
        cout << "An error occurred: " << e.what() << endl;
    }


    catch (...) 
    {
        cout << "An unknown error occurred." << endl;
    }
    
    system("pause");
    return 0;
}



