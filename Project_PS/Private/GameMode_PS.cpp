// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_PS.h"

void AGameMode_PS::BeginPlay()
{
    Super::BeginPlay();


    //GameStart 로 이동예정
    mColorObj = Cast<AGemColorObj>(GetWorld()->SpawnActor(AGemColorObj::StaticClass()));
    mBoard.Init(GetWorld(),&mpBoardStd);
    mBoard.MakeBoard(mpBoardStd.mSizeX, mpBoardStd.mSizeY,mSeed, mColorObj);
    FVector SpawnPos = FVector(mpBoardStd.mStartPos.X, mpBoardStd.mStartPos.Y, mpBoardStd.mBoardHight);

    FActorSpawnParameters SpawnParam;
    SpawnParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    FTransform ftrans;
    ftrans.SetLocation(SpawnPos);
    mpPlayerSpot =Cast<APlayerSpot>( GetWorld()->SpawnActor(APlayerSpot::StaticClass(), &ftrans, SpawnParam));
    mpPlayerSpot->mpBoardStd = &mpBoardStd;
    
    SpawnPos = ftrans.GetLocation();
    SpawnPos.Z += 100;
    ftrans.SetLocation(SpawnPos);
    mpPlayerCamera = Cast<APlayerCamera>(GetWorld()->SpawnActor(APlayerCamera::StaticClass(), &ftrans, SpawnParam));
    mpPlayerCamera->mpPlayerSpot = mpPlayerSpot;
    mpPlayerCamera->mpBoardStd = &mpBoardStd;
}

void AGameMode_PS::GameStart()
{
    
}