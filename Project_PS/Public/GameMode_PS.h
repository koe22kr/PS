// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameBoard.h"
#include "PlayerSpot.h"
#include "PlayerCamera.h"
#include "GemColorObj.h"
#include "GameFramework/GameModeBase.h"



#include "GameMode_PS.generated.h"

DECLARE_DELEGATE(FDelegate);
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
    Board_Std mpBoardStd;
    //UINT mSizeX=5;
    //UINT mSizeY=5;
    GameBoard mBoard;
    UINT mScore;

    AGemColorObj* mColorObj;
    APlayerSpot* mpPlayerSpot;
    APlayerCamera* mpPlayerCamera;

    double mSeed=1.0;//Goto std?

    FDelegate mDelegate;
};
