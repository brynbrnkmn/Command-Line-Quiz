//
//  PC7_10.cpp
//  PC7_10
//
//  Created by Bryan Brinkman on 4/23/17.
//  Copyright © 2017 Bryan Brinkman. All rights reserved.
//

#include <iostream>
using namespace std;

void answerChecker (char [], char [], int, int);

int main()
{
    const int question = 20;
    const int minPassing = 15;
    
    char answers [question] = {'A','D','B','B','C',
                               'B','A','B','C','D',
                               'A','C','D','B','D',
                               'C','C','A','D','B'};
    
    char examAnswer [question];
    
// Print input guidelines
    cout << "Enter either A, B, C, or D: " << endl;
    
    
// Loop student input
    for (int studentAnswer = 0; studentAnswer < question; studentAnswer++)
    {
        cout << "Enter your answer for question #" << (studentAnswer+1) << ": ";
        cin >> examAnswer[studentAnswer];
        
// Validation student input
        while (examAnswer[studentAnswer] != 'A' && examAnswer[studentAnswer] != 'B' && examAnswer[studentAnswer] != 'C' && examAnswer[studentAnswer] != 'D')
        {
            cout << "Oops! Only A, B, C or D are valid answers. Try again!\n";
            cout << "Enter your answer for question #" << (studentAnswer+1) << ": ";
            cin >> examAnswer[studentAnswer];
        }
    }
    
    answerChecker (answers, examAnswer, question, minPassing);
    
    return 0;
}

void answerChecker (char answerI[], char examAnswerI[], int question, int minPassing)
    {
        int yesAnswers = 0;
        cout << "\nYou need 15 correct to pass." << endl;
    
        for (int i=0; i < question; i++)
        {
            if (answerI[i] == examAnswerI[i])
            yesAnswers++;
        }
    
// Pass or Fail?
    if (yesAnswers >= minPassing)
    {
        cout << "\nNice! You passed!\n";
    }
    else
    {
        cout << "\nOops! You failed!\n";
    }
    
// Print incorrect questions
    cout << "\nThese questions were answered incorrectly...\n";
    
    for (int i = 0; i < question; i++)
    {
        if (answerI[i] != examAnswerI[i])
            cout << "Question # " << i << " is incorrect." << endl;
    }
    
// Print total correct and incorrect answers
    cout << "\nYou got " << yesAnswers << "correct!" << endl;
    cout << "\nYou got " << question - yesAnswers << " incorrect!" << endl;
}

