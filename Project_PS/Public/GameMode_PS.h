// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"


#include "GameBoard.h"
#include "GemColorObj.h"
#include "GameMode_PS.generated.h"


/**
 * 
 */
UCLASS()
class PROJECT_PS_API AGameMode_PS : public AGameModeBase
{
    GENERATED_BODY()


    virtual void BeginPlay();

public:
    void SetSeed(double seed) { mSeed = seed; };

public:
    void GameStart();


public:
    UINT mSizeX=5;
    UINT mSizeY=5;
    GameBoard mBoard;
    UINT mScore;

    AGemColorObj* mColorObj;

    double mSeed=1.0;


};
