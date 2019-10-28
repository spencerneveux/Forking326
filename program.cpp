#include<iostream>
#include<sys/wait.h>
#include<unistd.h>
#include<string>
#include<cstdlib>
#include<bits/stdc++.h>

using namespace std;

/*
Prompts user for word to search for
Returns user input
**/
int input() {
    int user_input;
    printf("Enter length of word: ");
    cin >> user_input;
    if (user_input == 0)
        exit(0);
    return user_input;
}

/*
Count number of words in document with given length
**/
int count(string document, int wordLength) {
    stringstream ss(document);
    string temp; 

    int count = 0;
    while(ss >> temp) {
        if (temp.length() == wordLength) 
            count++;
    }
    return count;
}

int execute(int count) {
    //Bug
    if (count == 0) {
        while(true)
            printf("Infinite Loop - %d\n", getpid());
    }else 
        printf("Count: %d\n", count);
        return 1;
}


int main() {
    string document = "The worst kind of weather for wildfires — strong, gusty winds and very low humidity — will return on Tuesday after a relative respite on Monday, the National Weather Service said, raising the prospect of more fire outbreaks and rapid growth of the blazes that are already burning."
"The agency has posted red flag warnings for most of Northern California and much of Southern California, taking effect at various times on Tuesday."
"Winds gusts of up to 60 miles an hour could be expected beginning in the morning over a vast stretch of the state from the Sierras to the Pacific and from the southern fringes of the Bay Area north nearly to the Oregon border, except for coastal areas north of Sonoma County."
"Similar conditions will develop Tuesday night from Santa Barbara south to the Mexican border and well inland, other than coastal areas south of Anaheim, and would persist into Thursday, forecasters said."
"Red-flag weather has played an important role in driving the growth of the Kincade, Getty and other fires, and has prompted pre-emptive blackouts by utility companies hoping to keep wind-damaged power lines and equipment from touching off more blazes"
"A brush fire that broke out early Monday morning on the western side of Los Angeles quickly consumed 600 acres, created gridlock on the 405, the nation’s busiest highway, and resulted in mandatory evacuations. But no fatalities were reported by midafternoon."
"The fire, known as the Getty fire, forced officials to seal off main interchanges of the 405 by midmorning. Offramps through the Sepulveda Pass, near where the fire started, were closed."
"The growing blaze caused the Los Angeles Unified School District, the Santa Monica-Malibu Unified School District and many private schools to close before classes were to begin. The University of California, Los Angeles and Santa Monica College also canceled classes. "
"The Los Angeles Fire Department dispatched crews to protect the Getty Center, home to priceless artworks and a new exhibition of Edouard Manet’s paintings.Capt. Erik Scott, a department spokesman, said the Getty Center, a billion-dollar complex in Los Angeles that houses an art museum with works by Rembrandt, van Gogh, Monet and Degas, was not immediately threatened by the blaze.";
    
    //Collect input
    int user_input = input();

    while(true) {
        //Create child
        int childPID = fork();

        if (childPID == 0) {
            //Count words with given length
            int wordCount = count(document, user_input);
            if(execute(wordCount))
                exit(0);
        }
        wait(NULL);
        printf("Parent Pid: %d Child PID: %d\n", getpid(), childPID);
        user_input = input();
    }
    return 0;
}
