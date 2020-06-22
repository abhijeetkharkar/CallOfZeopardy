// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Questionnaire.generated.h"

/**
 * 
 */
UCLASS()
class CALLOFZEOPARDY_API UQuestionnaire : public UBlueprintFunctionLibrary
{
	GENERATED_BODY() public:

		UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "LoadQuestionnaireData"))
			static bool LoadQuestionnaireData(FString FileName, TMap<int32, FString>& Questionnaire);

		UFUNCTION(BlueprintPure, Category = "Custom", meta = (Keywords = "SplitClueData"))
			static bool SplitClueData(FString ClueString, TArray<FString>& Clue);

		UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "SaveQuestionnaireData"))
			static bool SaveQuestionnaireData(FString Content, FString FileName);
	
};
