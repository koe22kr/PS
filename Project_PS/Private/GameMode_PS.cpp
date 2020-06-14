// Fill out your copyright notice in the Description page of Project Settings.


#include "GameMode_PS.h"

void AGameMode_PS::BeginPlay()
{
    Super::BeginPlay();

    //GameStart 로 이동예정
    mColorObj = Cast<AGemColorObj>(GetWorld()->SpawnActor(AGemColorObj::StaticClass()));
    mBoard.SetUWorld(GetWorld());
    mBoard.MakeBoard(mSizeX,mSizeY,mSeed, mColorObj);
}

void AGameMode_PS::GameStart()
{

}