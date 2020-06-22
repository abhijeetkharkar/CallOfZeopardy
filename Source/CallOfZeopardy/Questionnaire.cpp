// Fill out your copyright notice in the Description page of Project Settings.


#include "Questionnaire.h"
#include <string>
#include <sstream>
using namespace std;

bool UQuestionnaire::LoadQuestionnaireData(FString FileName, TMap<int32, FString>& Questionnaire)
{
    FString Result = FString(TEXT(""));
    bool result = FFileHelper::LoadFileToString(Result, *(FPaths::ProjectDir() + FileName));
    if (!result)
    {
        return false;
    }

    string Content = string(TCHAR_TO_UTF8(*Result));
    stringstream ss(Content); //convert my_string into string stream

    string row;

    int i = 0;
    while (getline(ss, row, '\n')) { //use comma as delim for cutting string
        string column;
        if (i > 0)
        {
            int j = 0;
            int32 key = 0;
            while (getline(stringstream(row), column, '|'))
            {
                if (j == 0)
                {
                    key = (int32)stoi(column);
                }
                else
                {
                    break;
                }
                j++;
            }
            Questionnaire.Add(key, FString(row.substr(row.find('|')+1).c_str()));
        }
        i++;
    }

    return true;
}

bool UQuestionnaire::SplitClueData(FString ClueString, TArray<FString>& Clue)
{
    stringstream s_stream(string(TCHAR_TO_UTF8(*ClueString)));
    while (s_stream.good())
    {
        string column;
        getline(s_stream, column, '|');
        Clue.Add(FString(column.c_str()));
    }

    return true;
}

bool UQuestionnaire::SaveQuestionnaireData(FString Content, FString FileName)
{
    return FFileHelper::SaveStringToFile(Content, *(FPaths::ProjectDir() + FileName));
}